#include "SoccerGame/SoccerGame.h"

#include <iostream>
#include <time.h>
#include "Logger/Logging.h"

SoccerGame::SoccerGame(PlayEngine *iPlayEngine, Navigator *iNavigator, Pathfinder *iPathfinder, int iTeam, int iPlayer) :
    mGame(0),
    mPlayEngine(iPlayEngine),
    mRunning(false),
    mNbTeams(iTeam),
    mNbPlayersPerTeam(iPlayer),
    mNavigator(iNavigator),
    mPathfinder(iPathfinder){

    this->loadConfig();
    //boost::asio::io_service mIOService;
    mVisionInputStream = new VisionInputStream(mIOService,"224.5.23.2",10020);
    mRefInputStream = new RefInputStream(mIOService,"224.5.23.1",10003);

    this->initOutput(mSimulationMode);

}

void SoccerGame::initOutput(bool iIsSimulation){
    if(iIsSimulation){
        INFO << "Creating GrSim Output Stream";
        try{
            mOutputStream = new UDPOutputStream(mIOService,mGrSimAddress,mGrSimPort);
        }
        catch(exception& e){
            ERROR << "Failed to create UDP socket : " << e.what();
        }
    }
    else{
        INFO << "Creating Serial Output Stream";
        try{
            mOutputStream = new SerialOutputStream(mSerialPort,mSerialBaud);
        }
        catch(exception& e){
            ERROR << "Failed to create Serial connection : " << e.what();
        }
    }
}

SoccerGame::~SoccerGame(){
    INFO << "Delete Game";
    delete mGame;
    delete mPlayEngine;
    delete mVisionInputStream;

    if(mOutputStream) delete mOutputStream;
}

bool SoccerGame::createSoccerGame(GameFactory iGameFactory){
    if(!this->createGame(iGameFactory)) return false;
    mGameEvaluator = new GameEvaluator(mGame);

    return true;
}

bool SoccerGame::createGame(GameFactory iFactory){
    bool lSuccess = true;

    Field* lField = iFactory.createField(mFieldWidth, mFieldHeight, mFieldPlayableWidth, mFieldPlayableHeight);

    BallId lBallId(0);
    Ball* lBall = iFactory.createBall(lBallId);

    Referee* lRef = iFactory.createRef();

    mGame = iFactory.createGame(lBall, lField, lRef);

    for(int i = 0; i < mNbTeams; i++){
        TeamId lTeamId(i);
        Team* lTeam = iFactory.createTeam(lTeamId);

        for(int j = 0; j < mNbPlayersPerTeam; j++){
            PlayerId lPlayerId(j);
            Player* lPlayer = iFactory.createPlayer(lPlayerId, lTeam->getId(),mNavigator);

            lTeam->addPlayer(lPlayer);

            this->mPathfinder->addPlayer(lPlayer);
        }

        mGame->addTeam(lTeam);
    }

    return lSuccess;
}

void SoccerGame::startGame(){
    INFO << "Starting Game";
    mRunning = true;
    this->initGame();

    clock_t lNow, lLastTime;

    while(mRunning){
        lLastTime = clock();

        this->update();

        lNow = clock();
        clock_t lDiff = lNow - lLastTime;
        if(lDiff < mDelay){
            long lTimeout = clock() + (mDelay - lDiff);
            INFO << "Wait for " << mDelay - lDiff << "ms";
            while( clock() < lTimeout ) continue;
        }
    }
}

void SoccerGame::initGame(){
    //get all player but Goalie into vector to pass to plays
    std::map<PlayerId, Player*> iPlayers = mGame->getTeams()[mOurTeamId]->getPlayers();
    for(auto it = iPlayers.begin(); it != iPlayers.end(); ++it){
        if(it->first != mGoalieId){
            INFO << "push Player:" << it->first.getValue();
            mRolablePlayers.push_back(it->first);
        }
    }
}


//MUTEX?
void SoccerGame::sendCommands(){
    if (mOutputStream != NULL){
        std::map<PlayerId, Player*> lPlayers = mGame->getTeams().begin()->second->getPlayers();
        std::map<PlayerId, Player*>::iterator it;

        for(it = lPlayers.begin();it != lPlayers.end();++it){
            CommandStruct lPlayerCommand = it->second->getCommand();
            if(lPlayerCommand.stopFlag){
                lPlayerCommand.positionTarget = Pose::ZERO;
            }
            mOutputStream->AddgrSimCommand(lPlayerCommand,false); //TODO set Team
        }
        mOutputStream->SendCommandDatagram();
    }
    else{
        ERROR << "No Output Stream!";
    }
}

void SoccerGame::updateNavigator(){    //for Qt test
    INFO << "Update Navigator QT";
    for(int i = 0; i < mNbPlayersPerTeam; ++i){
        Player * lPlayer = mGame->getTeams()[TeamId(0)]->getPlayers()[PlayerId(i)];
        lPlayer->move();
    }
    INFO << "Send Command qt";
    this->sendCommands();
}

void SoccerGame::updatePlayerGoal(Pose iPose){  //for Qt test
    Player * lPlayer = mGame->getTeams()[TeamId(0)]->getPlayers()[PlayerId(0)];
    lPlayer->addVectorToPath(iPose);
}

bool SoccerGame::loadConfig(){
    INFO << "Loading Configuration file";
    bool lSuccess = true;

    //TODO: Remove hardcoded values and load configs with boost::program_options

    mFieldWidth = 7400;
    mFieldHeight = 5400;
    mFieldPlayableWidth = 6050;
    mFieldPlayableHeight = 4050;
    mGoalieId = PlayerId(5);
    mOurTeamId = TeamId(0);

    mDelay = 5;

    mVisionAddress = "224.5.23.2";
    mVisionPort = 10020;
    mGrSimAddress = "127.0.0.1";
    mGrSimPort = 20011;
    mSerialPort = "/dev/USB0";
    mSerialBaud = 115200;

    mSimulationMode = true;

    return lSuccess;
}

void SoccerGame::update(){

    try{
         mIOService.run();
         mIOService.reset();
     }
     catch(std::exception& e){
         ERROR << e.what();
     }
    clock_t lNow, lLastTime;
    lLastTime = clock();
    this->mGame->unwrapPackets(mRefInputStream->getPacket(),mVisionInputStream->getPacket());
    Play* lCurrentPlay = mPlayEngine->update();
    lCurrentPlay->update(mRolablePlayers,mOurTeamId);

    for(int i = 0; i < mNbPlayersPerTeam; ++i){
        clock_t lNowPlayer, lLastTimePlayer;
        lLastTimePlayer = clock();
        Player * lPlayer = mGame->getTeams()[mOurTeamId]->getPlayers()[PlayerId(i)];
        std::pair<Tactic *, ParameterStruct> lTactic;
        if(i == mGoalieId.getValue()){
            lTactic = lCurrentPlay->getGoalieTactic();
        }
        else{
            lTactic = lCurrentPlay->getPlayerTactic(PlayerId(i));
        }
        std::pair<SkillStateMachine*,ParameterStruct> lSkill = lTactic.first->update(lTactic.second);
        CommandStruct lCommand = lSkill.first->update(lSkill.second);
        lPlayer->setCommand(lCommand);
        if(!lCommand.stopFlag){ //navigate flag!
            // TODO add new Path definition
            Planning::Path lPath = mPathfinder->findPath(lPlayer, lCommand.positionTarget);
            //for(int i =0; i < lPath.points.size(); i++){
            //    WARN << "["<<i<<"]  ("<< lPath.points[i].x << ", " << lPath.points[i].y<<")";
            //}
            //TODO erase this part or implement it in the pathfinder algorithm
            lPath.points.erase(lPath.points.begin());
            lPlayer->refreshPath(lPath);
            lPlayer->move();
        }

        lNowPlayer = clock();
        //INFO << "Player Execution Time = " << lNowPlayer - lLastTimePlayer;
    }

    this->sendCommands();
    mRunning = !mPlayEngine->isDone();
    lNow = clock();
    INFO << "Logic execution time = " << lNow - lLastTime << " ms";
}


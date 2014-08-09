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

    INFO << "Creating Game";
    this->loadConfig();
    INFO << "Creating vision input stream";
    //boost::asio::io_service mIOService;
    mInputStream = new InputStream(mIOService,"224.5.23.2",10020);

    this->initOuput(mSimulationMode);

}

void SoccerGame::initOuput(bool iIsSimulation){
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
    delete mInputStream;

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

    mGame = iFactory.createGame(lBall, lField);

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


//MUTEX?
void SoccerGame::sendCommands(){
    if (mOutputStream != NULL){
        std::map<PlayerId, Player*> lPlayers = mGame->getTeams().begin()->second->getPlayers();
        std::map<PlayerId, Player*>::iterator it;

        for(it = lPlayers.begin();it != lPlayers.end();++it){
            Pose lRep = it->second->getCommand();
            mOutputStream->AddgrSimCommand(lRep,false,it->first.getValue());
        }
        mOutputStream->SendCommandDatagram();
    }
}


void SoccerGame::unwrapVisionPacket(SSL_WrapperPacket iPacket){
    SSL_DetectionRobot lPacketRobotBlue;
    SSL_DetectionRobot lPacketRobotYellow;
    SSL_DetectionBall lPacketBall;
    if(iPacket.detection().balls_size()){
        lPacketBall = iPacket.detection().balls(0);
        mGame->getBall()->setPose(Pose(lPacketBall.x(),lPacketBall.y(),0));
    }

    Team* lBlueTeam = mGame->getTeams().find(TeamId(0))->second;
    Team* lYellowTeam = mGame->getTeams().find(TeamId(1))->second;

    std::map<PlayerId, Pose> lBlueVectorMap;
    std::map<PlayerId, Pose> lYellowVectorMap;

    int lBlueSize = iPacket.detection().robots_blue_size();
    int lYellowSize = iPacket.detection().robots_yellow_size();

    for(int i = 0; i < lBlueSize; ++i){
        lPacketRobotBlue = iPacket.detection().robots_blue(i);
        int lRobotId = lPacketRobotBlue.robot_id();
        lBlueVectorMap[PlayerId(lRobotId)]=Pose(lPacketRobotBlue.x(),
                                             lPacketRobotBlue.y(),
                                             lPacketRobotBlue.orientation());
    }

    for(int i = 0; i < lYellowSize; ++i){
        lPacketRobotYellow = iPacket.detection().robots_yellow(i);
        int lRobotId = lPacketRobotYellow.robot_id();
        lYellowVectorMap[PlayerId(lRobotId)]=Pose(lPacketRobotYellow.x(),
                                             lPacketRobotYellow.y(),
                                             lPacketRobotYellow.orientation());
    }

    lBlueTeam->updatePlayersPositions(lBlueVectorMap);
    lYellowTeam->updatePlayersPositions(lYellowVectorMap);

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

    mDelay = 5;

    mVisionAddress = "224.5.23.2";
    mVisionPort = 10020;
    mGrSimAddress = "127.0.0.1";
    mGrSimPort = 20011;
    mSerialPort = "/dev/USB";
    mSerialBaud = 115200;

    mSimulationMode = true;

    return lSuccess;
}

void SoccerGame::update(){

    //Retrieve players/ball positions
    try{
         mIOService.run();
         mIOService.reset();
     }
     catch(std::exception& e){
         ERROR << e.what();
     }
    clock_t lNow, lLastTime;
    lLastTime = clock();
    //Update players/ball positions
    this->unwrapVisionPacket(mInputStream->getVisionPacket());

    mPlayEngine->update(mGame->getTeams()[TeamId(0)]);


    for(int i = 0; i < mNbPlayersPerTeam; ++i){
        clock_t lNowPlayer, lLastTimePlayer;
        lLastTimePlayer = clock();
        Player * lPlayer = mGame->getTeams()[TeamId(0)]->getPlayers()[PlayerId(i)];
        std::pair<Tactic *, ParameterStruct> lTactic = lPlayer->getTactic();
        std::pair<SkillStateMachine*,ParameterStruct> lSkill = lTactic.first->update(lTactic.second);
        CommandStruct lCommand = lSkill.first->update(lSkill.second);

        // TODO add new Path definition
        Planning::Path lPath = mPathfinder->findPath(lPlayer,lCommand.target);
        lPlayer->refreshPath(lPath);
        lPlayer->move();
        lNowPlayer = clock();
        INFO << "Player Execution Time = " << lNowPlayer - lLastTimePlayer;
    }

    this->sendCommands();
    mRunning = !mPlayEngine->isDone();
    lNow = clock();
    INFO << "Send Command logic execution time = " << lNow - lLastTime << " ms";
}


/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is the core of the game. It is responsible to initiate
 *          the game by creating teams, players and ball. It manage the states
 *          of the game and update the positions of the objects in the game.
 *
 ****************************************************************************/
#ifndef SOCCER_GAME_H
#define SOCCER_GAME_H

#include <string>

#include "Game/Game.h"
#include "SoccerGame/Game/GameFactory.h"

#include "Strategy/PlayEngine.h"
#include "Strategy/GameEvaluator.h"

#include "Pathfinder/Pathfinder.h"

#include "Control/Navigator.h"

#include "InOut/InputStream.h"
#include "InOut/OutputStream.h"
#include "InOut/SerialOutputStream.h"
#include "InOut/UDPOutputStream.h"

class SoccerGame{
public:
    SoccerGame(PlayEngine *iPlayEngine, Navigator *iNavigator,Pathfinder *iPathfinder, int iTeam = 2, int iPlayer = 6);
    virtual ~SoccerGame();

    void initOuput(bool iIsSimulation);

    virtual bool createSoccerGame(GameFactory iGameFactory);
    virtual bool createGame(GameFactory iFactory);

    virtual void startGame();

    std::map<PlayerId, Pose> getTeamPositions(TeamId id) const;
    Pose getBallPosition() const;

    VisionInputStream* getVisionInputStream() const;
    OutputStream* getOutputStream() const;
    void setOuputStream(OutputStream* pOutputStream);
    void sendCommands();

    void updateNavigator(); //for Qt test
    void updatePlayerGoal(Pose iPose); //for Qt test

private:
    virtual bool loadConfig();
    virtual void update();


    PlayEngine *mPlayEngine;

    Game* mGame;
    GameEvaluator* mGameEvaluator;
    Navigator* mNavigator;
    Pathfinder* mPathfinder;
    bool mRunning;

    //Configs
    std::string mConfigFile();
    int mNbTeams;
    int mNbPlayersPerTeam;

    double mFieldWidth;
    double mFieldHeight;
    double mFieldPlayableWidth;
    double mFieldPlayableHeight;

    bool mSimulationMode;

    int mDelay;

    //IO
    VisionInputStream *mVisionInputStream;
    RefInputStream *mRefInputStream;
    OutputStream *mOutputStream;
    std::string mVisionAddress;
    int mVisionPort;
    std::string mGrSimAddress;
    int mGrSimPort;
    std::string mSerialPort;
    int mSerialBaud;

    boost::asio::io_service mIOService;
};

inline void SoccerGame::setOuputStream(OutputStream* pOutputStream){
    if(mOutputStream){  //clean the output if there was a previous connection
        delete mOutputStream;
        mOutputStream = NULL;
    }
    mOutputStream = pOutputStream;
}

inline VisionInputStream* SoccerGame::getVisionInputStream() const{
    return mVisionInputStream;
}

inline OutputStream* SoccerGame::getOutputStream() const{
    return mOutputStream;
}

inline std::map<PlayerId, Pose> SoccerGame::getTeamPositions(TeamId id) const{
    return mGame->getTeams().find(id)->second->getPlayersPosition();
}

inline Pose SoccerGame::getBallPosition() const{
    return mGame->getBall()->getPose();
}

#endif

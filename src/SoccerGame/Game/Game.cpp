#include "SoccerGame/Game/Game.h"

#include <boost/foreach.hpp>

Game::Game(Ball* iBall, Field* iField, Referee* iRef) :
    mField(iField),
    mBall(iBall),
    mRef(iRef){
}

Game::~Game() {
    if(mField) delete mField;
    if(mBall) delete mBall;

    this->tearDownTeams();
}

void Game::tearDownTeams(){
    BOOST_FOREACH(mTeamsPair i, mTeams){
        Team* lTeam = i.second;

        delete lTeam;
    }
}

Ball* Game::getBall() const{
    return mBall;
}

Field* Game::getField() const{
    return mField;
}

std::map<TeamId, Team*> Game::getTeams() const{
    return mTeams;
}

bool Game::addTeam(Team *iTeam){
    mTeamsPair lTeam(iTeam->getId(), iTeam);
    std::pair<std::map<TeamId, Team*>::iterator,bool> lResult;

    lResult = mTeams.insert(lTeam);

    if (lResult.second == false) {
        return false;
    }

    return true;
}

void Game::unwrapPackets(SSL_Referee* iRefPacket,SSL_WrapperPacket* iWrapperPacket){
    mRef->setData(iRefPacket);

    if(iWrapperPacket->detection().balls_size()){
        SSL_DetectionBall lPacketBall = iWrapperPacket->detection().balls(0);
        mBall->setPose(Pose(lPacketBall.x(),lPacketBall.y(),0));
    }

    mTeams[TeamId(0)]->setPlayersPositions(iWrapperPacket->detection().robots_blue());
    mTeams[TeamId(1)]->setPlayersPositions(iWrapperPacket->detection().robots_yellow());

}

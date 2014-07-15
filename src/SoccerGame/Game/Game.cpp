#include "SoccerGame/Game/Game.h"

#include <boost/foreach.hpp>

Game::Game(Ball* iBall, Field* iField) :
    mField(iField),
    mBall(iBall){
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

#include "SoccerGame/Team/Team.h"

#include "SoccerGame/Exception/RobocupException.h"

Team::Team(const TeamId &iId) :
    mId(iId){
}

bool Team::addPlayer(Player *iPlayer){
    mPlayersPair lPlayer(iPlayer->getId(), iPlayer);
    std::pair<std::map<PlayerId, Player*>::iterator,bool> lResult;

    lResult = mPlayers.insert(lPlayer);

    if (lResult.second == false) {
        return false;
    }

    return true;
}

std::map<PlayerId, Player*> Team::getPlayers() const{
    return mPlayers;
}

bool Team::hasPlayer(PlayerId iPlayerId) const {
    try {
        this->findPlayerByID(iPlayerId);
    }
    catch(PlayerNotFoundException){
        return false;
    }

    return true;
}

void Team::updatePlayersPositions(const std::map<PlayerId, Pose> &iPositions) {
    for (std::map<PlayerId, Pose>::const_iterator it = iPositions.begin(); it != iPositions.end(); it++) {
        if(hasPlayer(it->first)){
            this->findPlayerByID(it->first)->setPose(it->second);
        }
    }
}

Player* Team::findPlayerByID(PlayerId iPlayerId) const{
    std::map<PlayerId, Player*>::const_iterator it = mPlayers.find(iPlayerId);

    if(it == mPlayers.end()){
        throw PlayerNotFoundException("Unable to find player");
    }

    return it->second;
}

std::map<PlayerId, Pose> Team::getPlayersPosition() const{
    std::map<PlayerId, Pose> lPositionMap;
    for (std::map<PlayerId, Player*>::const_iterator it = mPlayers.begin(); it != mPlayers.end(); it++) {
        lPositionMap[it->first] = it->second->getPose();
    }
    return lPositionMap;
}

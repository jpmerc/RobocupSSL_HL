#include "Strategy/Play/Play.h"



void Play::reset(){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        (*it)->setAssignation(false);
    }
}

Role* Play::getRole(int iId){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iId == (*it)->getId()){
            return (*it);
        }
    }
    //else
    throw RoleNotFoundException("No Ids matching for getRole()");
}

std::pair<Tactic*,ParameterStruct> Play::getPlayerTactic(PlayerId iPlayer){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iPlayer == (*it)->getCurrentPlayer()){
            return (*it)->getCurrentTactic();
        }
    }
    //else
    std::ostringstream ss;
    ss << "Player with id : " << iPlayer.getValue() << "Have no Role assigned!";
    throw RoleNotFoundException(ss.str());
}

void Play::assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers){

    //should create the player's list and pass it to the role, he will ask the tactic wich player
    std::vector<PlayerId> lPlayers;
    for(auto it = iPlayers.begin(); it != iPlayers.end(); ++it){
        lPlayers.push_back(it->first);
    }
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){

        if(!(*it)->isAssigned()){
            (*it)->assignTacticToPlayer(lPlayers);
        }
    }

}

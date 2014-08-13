#include "Strategy/Play/Play.h"


Play::Play(){
    std::vector<std::pair<Tactic *, ParameterStruct>> lTacticVector;
    std::pair<Tactic *, ParameterStruct> lTactic(new Goalie(), ParameterStruct());
    lTacticVector.push_back(lTactic);
    mGoalieRole = new Role(lTacticVector,5);
    std::vector<PlayerId> goal;
    goal.push_back(PlayerId(5));
    mGoalieRole->assignTacticToPlayer(goal,TeamId(0));
}

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

std::pair<Tactic*,ParameterStruct> Play::getGoalieTactic(){
    return mGoalieRole->getCurrentTactic();
}

void Play::assignRoleToPlayers(std::vector<PlayerId> iPlayers,TeamId iTeam){

    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){

        if(!(*it)->isAssigned()){
            (*it)->assignTacticToPlayer(iPlayers,iTeam);
        }
    }

}

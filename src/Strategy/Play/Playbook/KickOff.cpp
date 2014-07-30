#include "Strategy/Play/Playbook/KickOff.h"

KickOff::KickOff(){
    INFO << "Create KickOff Play";
    this->createRoles();
}

void KickOff::update(){
    //look if important tactic finished, if it is, in crement tactic
}

void KickOff::requestPlay(){

}

void KickOff::createRoles(){

    mPositions.push_back(Pose(-2500,0,0));
    mPositions.push_back(Pose(-1800,800,0));
    mPositions.push_back(Pose(-1800,-800,0));
    mPositions.push_back(Pose(-800,0,0));
    mPositions.push_back(Pose(-100,1000,0));
    mPositions.push_back(Pose(-100,-1000,0));

    for(int i = 0; i < 6;++i){
        std::vector<std::pair<Tactic *, ParameterStruct>> lTacticVector;
        std::pair<Tactic *, ParameterStruct> lTactic(new Position(), ParameterStruct(mPositions[i]));
        lTacticVector.push_back(lTactic);
        mAvailableRoles.push_back(new Role(lTacticVector,i));
    }
}

void KickOff::assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers){

    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){

        if(!(*it)->isAssigned()){
            std::pair<Tactic *, ParameterStruct> lTactic = (*it)->getCurrentTactic();
            PlayerId lPlayerId = GameEvaluator::getClosestPlayerWithoutRole(TeamId(0),lTactic.second.positionTarget.Position); //TODO : change team id..
            (*it)->setAssignation(true);
            iPlayers[lPlayerId]->setRole(*it);
            INFO << "Player : " << lPlayerId.getValue() << " got role : " << (*it)->getId();
        }
    }

}

Role* KickOff::getRole(int iId){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iId == (*it)->getId()){
            return (*it);
        }
    }
    //else
    throw RoleNotFoundException("No Ids matching for getRole()");
}

bool KickOff::isDone(){

}

int KickOff::scoreCurrentSituation(){

}
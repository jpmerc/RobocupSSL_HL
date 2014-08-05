#include "Strategy/Play/Playbook/Idle.h"

Idle::Idle(){
    INFO << "Create Idle Play";
    this->createRoles();
}

void Idle::update(){
    //look if important tactic finished, if it is, increment tactic
    INFO << "Update Idle";
}

void Idle::reset(){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        (*it)->setAssignation(false);
    }
}

void Idle::requestPlay(){

}

void Idle::createRoles(){
    for(int i = 0; i < 6;++i){
        std::vector<std::pair<Tactic *, ParameterStruct>> lTacticVector;
        ParameterStruct lParam;
        lParam.isIdle = true;
        std::pair<Tactic *, ParameterStruct> lTactic(new Position(), lParam);
        lTacticVector.push_back(lTactic);
        mAvailableRoles.push_back(new Role(lTacticVector,i));
    }
}

void Idle::assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers){

    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){

        if(!(*it)->isAssigned()){
            (*it)->setAssignation(true);
            iPlayers[(*it)->getId()]->setRole(*it);
            INFO << "Player : " << iPlayers[(*it)->getId()]->getId().getValue() << " got role : " << (*it)->getId();
        }
    }
}

Role* Idle::getRole(int iId){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iId == (*it)->getId()){
            return (*it);
        }
    }
    //else
    throw RoleNotFoundException("No Ids matching for getRole()");
}

bool Idle::isDone(){

}

int Idle::scoreCurrentSituation(){

}

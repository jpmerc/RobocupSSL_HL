#include "Strategy/Play/Playbook/Idle.h"

Idle::Idle(){
    INFO << "Create Idle Play";
    this->createRoles();
}

void Idle::update(){
    //look if important tactic finished, if it is, in crement tactic
}

void Idle::requestPlay(){

}

void Idle::createRoles(){

}

void Idle::assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers){

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

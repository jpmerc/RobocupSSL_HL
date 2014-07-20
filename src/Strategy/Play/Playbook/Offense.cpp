#include "Strategy/Play/Playbook/Offense.h"

Offense::Offense(){
    INFO << "Create Offense Play";
    this->createRoles();
}

void Offense::update(){
    //look if important tactic finished, if it is, in crement tactic
}

void Offense::requestPlay(){

}

void Offense::createRoles(){
    std::vector<Tactic *> lTactic;
    lTactic.push_back(new Position());

    for(int i = 0; i < 5;++i){
        mAvailableRoles.push_back(new Role(lTactic,0));
    }
}

void Offense::assignRoleToPlayer(Player *iPlayer){
    iPlayer->setRole(mAvailableRoles[iPlayer->getId().getValue()]);  //for now
    INFO << "Player " << iPlayer->getId().getValue() << " Have a Role";
}

bool Offense::isDone(){

}

int Offense::scoreCurrentSituation(){

}


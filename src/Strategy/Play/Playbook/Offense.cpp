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
    //find a more elegant and simple way to create tactics and there parameters
    std::vector<std::pair<Tactic *, ParameterStruct>> lTactic;
    std::pair<Tactic *, ParameterStruct> lFirstTactic;
    ParameterStruct lFirstParam;
    lFirstParam.target = Pose(100,100);
    lFirstTactic.first = new Position();
    lFirstTactic.second = lFirstParam;

    lTactic.push_back(lFirstTactic);

    for(int i = 0; i < 6;++i){
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


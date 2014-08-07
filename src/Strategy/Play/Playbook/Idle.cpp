#include "Strategy/Play/Playbook/Idle.h"

Idle::Idle(){
    INFO << "Create Idle Play";
    this->createRoles();
}

void Idle::update(std::map<PlayerId, Player*> iPlayers){
    //look if important tactic finished, if it is, increment tactic
    INFO << "Update Idle";
    this->assignRoleToPlayers(iPlayers);
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

bool Idle::isDone(){

}


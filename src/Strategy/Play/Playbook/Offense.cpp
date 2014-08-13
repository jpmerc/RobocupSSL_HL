#include "Strategy/Play/Playbook/Offense.h"

Offense::Offense(){
    INFO << "Create Offense Play";
    this->createRoles();
}

void Offense::update(std::vector<PlayerId> iPlayers, TeamId iTeam){
    //look if important tactic finished, if it is, in crement tactic
    this->assignRoleToPlayers(iPlayers,iTeam);
}

void Offense::requestPlay(){

}

void Offense::createRoles(){

    mPositions.push_back(Pose(-1800,800,0));
    mPositions.push_back(Pose(-1800,-800,0));
    mPositions.push_back(Pose(-800,0,0));
    mPositions.push_back(Pose(-100,1000,0));
    mPositions.push_back(Pose(-100,-1000,0));

    for(int i = 0; i < 5;++i){
        std::vector<std::pair<Tactic *, ParameterStruct>> lTacticVector;
        std::pair<Tactic *, ParameterStruct> lTactic(new Position(), ParameterStruct(mPositions[i]));
        lTacticVector.push_back(lTactic);
        mAvailableRoles.push_back(new Role(lTacticVector,i));
    }
}


bool Offense::isDone(){

}



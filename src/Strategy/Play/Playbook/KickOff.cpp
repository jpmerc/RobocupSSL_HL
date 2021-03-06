#include "Strategy/Play/Playbook/KickOff.h"

KickOff::KickOff(){
    INFO << "Create KickOff Play";
    this->createRoles();
}

void KickOff::update(std::vector<PlayerId> iPlayers, TeamId iTeam){
    //look if important tactic finished, if it is, increment tactic
    INFO << "Update KickOff";
    this->assignRoleToPlayers(iPlayers,iTeam);
}

void KickOff::requestPlay(){

}

void KickOff::createRoles(){

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




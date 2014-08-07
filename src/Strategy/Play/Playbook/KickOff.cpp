#include "Strategy/Play/Playbook/KickOff.h"

KickOff::KickOff(){
    INFO << "Create KickOff Play";
    this->createRoles();
}

void KickOff::update(std::map<PlayerId, Player*> iPlayers){
    //look if important tactic finished, if it is, increment tactic
    INFO << "Update KickOff";
    this->assignRoleToPlayers(iPlayers);
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

    std::vector<PlayerId> lPlayers;
    for(auto it = iPlayers.begin(); it != iPlayers.end(); ++it){
        lPlayers.push_back(it->first);
    }
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){

        if(!(*it)->isAssigned()){
            std::pair<Tactic *, ParameterStruct> lTactic = (*it)->getCurrentTactic();
            PlayerId lPlayerId = GameEvaluator::getClosestPlayer(lPlayers,TeamId(0),lTactic.second.positionTarget.Position); //TODO : change team id..
            (*it)->setAssignation(true);
            iPlayers[lPlayerId]->setRole(*it);
            INFO << "Player : " << lPlayerId.getValue() << " got role : " << (*it)->getId();
        }
    }

}


bool KickOff::isDone(){

}

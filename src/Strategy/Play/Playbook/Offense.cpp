#include "Strategy/Play/Playbook/Offense.h"

Offense::Offense(){
    INFO << "Create Offense Play";
    this->createRoles();
}

void Offense::update(){
    //look if important tactic finished, if it is, in crement tactic
}

void Offense::reset(){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        (*it)->setAssignation(false);
    }
}

void Offense::requestPlay(){

}

void Offense::createRoles(){

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

void Offense::assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers){
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

Role* Offense::getRole(int iId){
    for (auto it=mAvailableRoles.begin(); it!=mAvailableRoles.end(); ++it){
        if(iId == (*it)->getId()){
            return (*it);
        }
    }
    //else
    throw RoleNotFoundException("No Ids matching for getRole()");
}

bool Offense::isDone(){

}

int Offense::scoreCurrentSituation(){

}


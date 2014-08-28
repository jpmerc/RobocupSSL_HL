#include "Strategy/Tactic/Goalie.h"

Goalie::Goalie(){
    INFO << "Create Goalie Tactic";
    this->setState(state::DEFEND_GOAL);
}

std::pair<SkillStateMachine*,ParameterStruct> Goalie::update(ParameterStruct iParam){
    iParam.positionTarget = Pose(-2500,0,0);
    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

PlayerId Goalie::getBestPlayer(TeamId iTeam, std::vector<PlayerId>& iPlayers, ParameterStruct iParam){

    PlayerId lPlayerId = *iPlayers.begin();
    return lPlayerId;
}

bool Goalie::isDone(){

}

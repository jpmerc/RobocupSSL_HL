#include "Strategy/Tactic/DribbleToPosition.h"

DribbleToPosition::DribbleToPosition(){
    INFO << "Create DribbleToPosition Tactic";
    mActualSSM = new DriveToBall();
}

std::pair<SkillStateMachine*,ParameterStruct> DribbleToPosition::update(ParameterStruct iParam){
    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

PlayerId DribbleToPosition::getBestPlayer(TeamId iTeam, std::vector<PlayerId>& iPlayers, ParameterStruct iParam){

    PlayerId lPlayerId = GameEvaluator::getClosestPlayer(iPlayers,iTeam,GameEvaluator::getBallPose().Position);
    return lPlayerId;
}

bool DribbleToPosition::isDone(){

}

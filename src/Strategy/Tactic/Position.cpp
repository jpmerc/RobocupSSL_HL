#include "Strategy/Tactic/Position.h"

Position::Position(){
    INFO << "Create Position Tactic";
    this->setState(state::DRIVE_TO_POSITION);
}

std::pair<SkillStateMachine*,ParameterStruct> Position::update(ParameterStruct iParam){
    double distance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,iParam.teamId,iParam.positionTarget.Position);

    //INFO << "Robot's distance = " << distance;
    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

PlayerId Position::getBestPlayer(TeamId iTeam, std::vector<PlayerId>& iPlayers, ParameterStruct iParam){

    PlayerId lPlayerId = GameEvaluator::getClosestPlayer(iPlayers,iTeam,iParam.positionTarget.Position); //TODO : change team id..
    return lPlayerId;
}

bool Position::isDone(){

}

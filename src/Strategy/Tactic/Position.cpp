#include "Strategy/Tactic/Position.h"

Position::Position(){
    INFO << "Create Position Tactic";
    mActualSSM = new DriveToPosition();
}

std::pair<SkillStateMachine*,ParameterStruct> Position::update(ParameterStruct iParam){
    double distance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,iParam.teamId,iParam.positionTarget.Position);

    //INFO << "Robot's distance = " << distance;
    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

virtual PlayerId Position::getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers){

}

bool Position::isDone(){

}

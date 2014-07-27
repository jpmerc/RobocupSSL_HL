#include "Strategy/Tactic/Position.h"

Position::Position(){
    INFO << "Create Position Tactic";
    mActualSSM = new DriveToTarget();
}

std::pair<SkillStateMachine*,ParameterStruct> Position::update(ParameterStruct iParam){
    double distance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,iParam.teamId,iParam.target.Position);

    //INFO << "Robot's distance = " << distance;
    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

bool Position::isDone(){

}

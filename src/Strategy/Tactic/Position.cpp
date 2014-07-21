#include "Strategy/Tactic/Position.h"

Position::Position(){
    INFO << "Create Position Tactic";
    mActualSSM = new DriveToTarget();
}

void Position::update(ParameterStruct iParam){
    double distance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,iParam.teamId,iParam.target.Position);

    INFO << "Robot's distance = " << distance;
    mActualSSM->update(iParam);
}

bool Position::isDone(){

}

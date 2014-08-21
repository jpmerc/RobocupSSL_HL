#include "Strategy/Skill/DriveToBall.h"

DriveToBall::DriveToBall(){
}

CommandStruct DriveToBall::update(ParameterStruct iParam){

    mCurrentSkill = new Move();
    iParam.positionTarget = GameEvaluator::getBallPose();
    iParam.positionTarget.Angle = Orientation(GameEvaluator::getAngleBetweenPlayerAndBall(iParam.playerId,iParam.teamId));
    return (*mCurrentSkill)(iParam);
}

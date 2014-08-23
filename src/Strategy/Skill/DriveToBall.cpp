#include "Strategy/Skill/DriveToBall.h"

DriveToBall::DriveToBall(){
}

CommandStruct DriveToBall::update(ParameterStruct iParam){

    iParam.positionTarget = GameEvaluator::getBallPose();
    iParam.positionTarget.Angle = Orientation(GameEvaluator::getAngleBetweenPlayerAndBall(iParam.playerId,iParam.teamId));
    //Evaluate if he is close enough to stop
    if(GameEvaluator::playerAsBall(iParam.playerId,iParam.teamId,AIConst::BallAngleTresh,AIConst::BallDistanceTresh)){
        // TODO make a rotation with the ball
        mCurrentSkill = new Stop();
        iParam.canDrible = true;
        this->mTerminated = true;
    }
    else{
        mCurrentSkill = new Move();
        iParam.canDrible = false;
    }


    return (*mCurrentSkill)(iParam);
}

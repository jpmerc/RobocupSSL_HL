#include "Strategy/Skill/DriveToPosition.h"

DriveToPosition::DriveToPosition(){
}

CommandStruct DriveToPosition::update(ParameterStruct iParam){
    if(iParam.isIdle){
        mCurrentSkill = new Stop();
    }
    else{
        mCurrentSkill = new Move();
    }

    double lDistance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,iParam.teamId,iParam.positionTarget.Position);

    if(lDistance < 100){
        mTerminated = true;
    }

    return (*mCurrentSkill)(iParam);
}

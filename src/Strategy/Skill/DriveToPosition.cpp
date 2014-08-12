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

    return (*mCurrentSkill)(iParam);
}

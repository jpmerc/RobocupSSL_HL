#include "Strategy/Skill/DriveToTarget.h"

DriveToTarget::DriveToTarget(){
}

CommandStruct DriveToTarget::update(ParameterStruct iParam){
    mCurrentSkill = new Move();

    return (*mCurrentSkill)(iParam);
}

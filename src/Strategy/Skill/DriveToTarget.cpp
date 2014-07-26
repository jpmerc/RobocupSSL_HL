#include "Strategy/Skill/DriveToTarget.h"

DriveToTarget::DriveToTarget(){
    mActualSkill = new Move();
}

CommandStruct DriveToTarget::update(ParameterStruct iParam){
    return mActualSkill->update(iParam);
}

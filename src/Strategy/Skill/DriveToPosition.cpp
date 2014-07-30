#include "Strategy/Skill/DriveToPosition.h"

DriveToPosition::DriveToPosition(){
    mActualSkill = new Move();
}

CommandStruct DriveToPosition::update(ParameterStruct iParam){
    return mActualSkill->update(iParam);
}

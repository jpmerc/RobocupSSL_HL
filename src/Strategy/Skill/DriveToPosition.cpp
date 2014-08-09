#include "Strategy/Skill/DriveToPosition.h"

DriveToPosition::DriveToPosition(){
    mActualSkill = new Move();
}

CommandStruct DriveToPosition::update(ParameterStruct iParam){
    if(iParam.isIdle){
        mActualSkill = new Stop();
    }
    else{
        mActualSkill = new Move();
    }
    return mActualSkill->update(iParam);
}

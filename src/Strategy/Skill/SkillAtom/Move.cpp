#include "Strategy/Skill/SkillAtom/Move.h"

Move::Move(){

}

CommandStruct Move::operator()(ParameterStruct iParam){
    CommandStruct command;
    command.positionTarget = iParam.positionTarget;
    command.kickFlag = iParam.canKick;
    command.dribleFlag = iParam.canDrible;
    return command;
}

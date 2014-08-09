#include "Strategy/Skill/SkillAtom/Move.h"

Move::Move(){

}

CommandStruct Move::update(ParameterStruct iParam){
    CommandStruct command;
    command.positionTarget = iParam.positionTarget;
    return command;
}

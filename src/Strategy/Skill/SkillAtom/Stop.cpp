#include "Strategy/Skill/SkillAtom/Stop.h"

Stop::Stop(){

}

CommandStruct Stop::operator()(ParameterStruct iParam){
    CommandStruct command;
    command.stopFlag = true;
    command.kickFlag = iParam.canKick;
    command.dribleFlag = iParam.canDrible;
    return command;
}

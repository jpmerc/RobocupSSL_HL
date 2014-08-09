#include "Strategy/Skill/SkillAtom/Stop.h"

Stop::Stop(){

}

CommandStruct Stop::update(ParameterStruct iParam){
    CommandStruct command;
    command.stopFlag = true;
    return command;
}

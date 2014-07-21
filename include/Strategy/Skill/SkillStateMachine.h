#ifndef SKILLSTATEMACHINE_H
#define SKILLSTATEMACHINE_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"

class SkillStateMachine{
public:
    SkillStateMachine(){}

    virtual void update(ParameterStruct iParam) = 0;

protected:
    Skill * mActualSkill;

};

#endif // SKILLSTATEMACHINE_H

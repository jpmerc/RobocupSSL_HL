#ifndef SKILLSTATEMACHINE_H
#define SKILLSTATEMACHINE_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillAtom/Stop.h"
#include "Strategy/Skill/SkillAtom/Move.h"
#include "Strategy/CommandStruct.h"

class SkillStateMachine{
public:
    SkillStateMachine();

    virtual CommandStruct update(ParameterStruct iParam) = 0;

protected:

    Skill* mCurrentSkill;
};

#endif // SKILLSTATEMACHINE_H

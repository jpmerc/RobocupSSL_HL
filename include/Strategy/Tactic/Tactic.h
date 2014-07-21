#ifndef TACTIC_H
#define TACTIC_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillStateMachine.h"

class Tactic
{
public:
    Tactic(){}

    virtual void update(ParameterStruct iParam) = 0;

    virtual bool isDone() = 0;
protected:
    SkillStateMachine* mActualSSM;

};

#endif // TACTIC_H

#ifndef SKILLSTATEMACHINE_H
#define SKILLSTATEMACHINE_H

#include "Logger/Logging.h"
#include "Strategy/AIConstants.hpp"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillAtom/Stop.h"

class Move;
class CommandStruct;
class ParameterStruct;

class SkillStateMachine{
public:
    SkillStateMachine();

    virtual CommandStruct update(ParameterStruct iParam) = 0;
    bool isDone();

protected:

    Skill* mCurrentSkill;
    bool mTerminated;
};

inline bool SkillStateMachine::isDone(){
    return mTerminated;
}


#endif // SKILLSTATEMACHINE_H

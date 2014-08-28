#ifndef DEFENDGOAL_H
#define DEFENDGOAL_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillStateMachine.h"
#include "Strategy/Skill/SkillAtom/Move.h"
#include "Strategy/Skill/SkillAtom/Stop.h"
#include "Strategy/CommandStruct.h"
#include "Utils/Line.h"
#include "Strategy/GameEvaluator.h"

class DefendGoal:public SkillStateMachine{
public:
    DefendGoal();

    virtual CommandStruct update(ParameterStruct iParam);

};

#endif // DEFENDGOAL_H

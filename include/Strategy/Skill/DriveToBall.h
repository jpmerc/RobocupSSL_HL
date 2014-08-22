#ifndef DRIVETOBALL_H
#define DRIVETOBALL_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillStateMachine.h"
#include "Strategy/Skill/SkillAtom/Move.h"
#include "Strategy/Skill/SkillAtom/Stop.h"
#include "Strategy/CommandStruct.h"
#include "Strategy/GameEvaluator.h"

class DriveToBall:public SkillStateMachine{
public:
    DriveToBall();

    virtual CommandStruct update(ParameterStruct iParam);


};

#endif // DRIVETOBALL_H

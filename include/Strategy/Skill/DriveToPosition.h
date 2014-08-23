#ifndef DRIVETOPOSITION_H
#define DRIVETOPOSITION_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillStateMachine.h"
#include "Strategy/Skill/SkillAtom/Move.h"
#include "Strategy/Skill/SkillAtom/Stop.h"
#include "Strategy/CommandStruct.h"
#include "Strategy/GameEvaluator.h"

class DriveToPosition:public SkillStateMachine{
public:
    DriveToPosition();

    virtual CommandStruct update(ParameterStruct iParam);

};

#endif // DRIVETOPOSITION_H

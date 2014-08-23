#ifndef DRIVETOTARGET_H
#define DRIVETOTARGET_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"
#include "Strategy/Skill/SkillStateMachine.h"
#include "Strategy/Skill/SkillAtom/Move.h"
#include "Strategy/CommandStruct.h"

class DriveToTarget:public SkillStateMachine{
public:
    DriveToTarget();

    virtual CommandStruct update(ParameterStruct iParam);

};

#endif // DRIVETOTARGET_H

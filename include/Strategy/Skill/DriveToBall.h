#ifndef DRIVETOBALL_H
#define DRIVETOBALL_H

#include "Strategy/Skill/SkillStateMachine.h"
#include "Strategy/GameEvaluator.h"
#include "Strategy/Skill/SkillAtom/Move.h"

class Stop;
class CommandStruct;
class ParameterStruct;

class DriveToBall:public SkillStateMachine{
public:
    DriveToBall();

    virtual CommandStruct update(ParameterStruct iParam);

};

#endif // DRIVETOBALL_H

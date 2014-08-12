#ifndef MOVE_H
#define MOVE_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"

class Move:public Skill{
public:
    Move();

    virtual CommandStruct operator()(ParameterStruct iParam);

private:


};

#endif // MOVE_H

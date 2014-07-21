#ifndef SKILL_H
#define SKILL_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"

class Skill
{
public:
    Skill(){}

    virtual void update(ParameterStruct iParam) = 0;

private:


};

#endif // SKILL_H

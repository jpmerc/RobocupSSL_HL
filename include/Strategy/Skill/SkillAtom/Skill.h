#ifndef SKILL_H
#define SKILL_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/CommandStruct.h"

class Skill
{
public:
    Skill(){}

    virtual CommandStruct update(ParameterStruct iParam) = 0;

private:


};

#endif // SKILL_H

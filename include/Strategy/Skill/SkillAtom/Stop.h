#ifndef STOP_H
#define STOP_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillAtom/Skill.h"

class Stop:public Skill{
public:
    Stop();

    virtual CommandStruct update(ParameterStruct iParam);

private:


};

#endif // STOP_H

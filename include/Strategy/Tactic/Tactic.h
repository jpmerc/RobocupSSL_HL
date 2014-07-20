#ifndef TACTIC_H
#define TACTIC_H

#include "Logger/Logging.h"

class Tactic
{
public:
    Tactic(){}

    virtual void update() = 0;

    virtual bool isDone() = 0;
};

#endif // TACTIC_H

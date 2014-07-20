#ifndef POSITION_H
#define POSITION_H

#include "Logger/Logging.h"
#include "Strategy/Tactic/Tactic.h"

class Position: public Tactic{
public:
    Position();

    virtual void update();

    virtual bool isDone();
};

#endif // POSITION_H

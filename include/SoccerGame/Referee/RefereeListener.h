#ifndef REFEREELISTENER_H
#define REFEREELISTENER_H

#include "Referee.h"

class RefereeListener
{
public:
    virtual ~RefereeListener(){}
protected:
    RefereeListener(){}

    virtual void gameStarted() = 0;
    virtual void gamePaused() = 0;
    virtual void gameEnded() = 0;

    friend class Referee;
};

#endif // REFEREELISTENER_H

#ifndef REFEREE_LISTENER_H
#define REFEREE_LISTENER_H

#include "Game/Player/PlayerId.h"

class RefereeListener {
public:
    virtual void resume() = 0;
    virtual void end() = 0;
    virtual void endHalve() = 0;

    virtual void score(int actingTeamID) = 0;
    virtual void faceoff() = 0;
    virtual void timeOut() = 0;
    virtual void penaltyKick(const PlayerId &faultedPlayerIdentification) = 0;
    virtual void directFreeKick(int faultyTeamID) = 0;
    virtual void indirectFreeKick(int faultyTeamID) = 0;
    virtual void cornerKick(int faultyTeamID) = 0;
    virtual void throwIn(int faultyTeamID) = 0;
};

#endif

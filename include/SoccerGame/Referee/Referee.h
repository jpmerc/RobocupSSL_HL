#ifndef REFEREE_H
#define REFEREE_H

#include <vector>

#include "RefereeListener.h"

class RefereeListener;

class Referee
{
public:
    Referee();

    void addListener(RefereeListener *listener);
private:
    void fireGameStarted();
    void fireGamePaused();
    void fireGameEnded();

    std::vector<RefereeListener*> listeners;
};

#endif // REFEREE_H

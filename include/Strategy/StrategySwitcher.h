#ifndef STRATEGYSWITCHER_H
#define STRATEGYSWITCHER_H

#include "SoccerGame/Referee/RefereeListener.h"

#include "Strategy/Play/PlayFinder.h"
#include "Strategy/Play/Play.h"

class StrategySwitcher : public RefereeListener
{
public:
    StrategySwitcher();
    ~StrategySwitcher();

    bool isDone();

    void update();
protected:
    virtual void gameStarted();
    virtual void gamePaused();
    virtual void gameEnded();

    std::vector<Play*> availablePlays;
private:
    void findNextPlay();
    void switchPlays(Play *newPlay);

    void onGameStarted();
    void onGamePaused();
    void onGameEnded();

    PlayFinder playFinder;
    Play *currentPlay;

    bool isGameEnded;
};

#endif // STRATEGYSWITCHER_H

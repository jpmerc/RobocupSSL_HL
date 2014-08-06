#ifndef PLAYENGINE_H
#define PLAYENGINE_H

#include "SoccerGame/Team/Team.h"
#include "SoccerGame/Player/Player.h"

#include "Strategy/Play/PlayFinder.h"
#include "Strategy/Play/Play.h"
#include "Strategy/Role.h"

#include "Strategy/Play/Playbook/Offense.h"
#include "Strategy/Play/Playbook/KickOff.h"
#include "Strategy/Play/Playbook/Idle.h"

#include "Logger/Logging.h"

class PlayEngine
{
public:
    PlayEngine();
    ~PlayEngine();

    bool isDone();

    Play * update();
protected:
    virtual void gameStarted();
    virtual void gamePaused();
    virtual void gameEnded();

    std::vector<Play*> mAvailablePlays;
private:

    void findNextPlay();
    void switchPlays(Play *newPlay);

    void onGameStarted();
    void onGamePaused();
    void onGameEnded();

    //PlayFinder mPlayFinder;
    Play *mCurrentPlay;

    bool isGameEnded;
};

#endif // PLAYENGINE_H

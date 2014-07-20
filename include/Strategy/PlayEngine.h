#ifndef PLAYENGINE_H
#define PLAYENGINE_H

#include "SoccerGame/Referee/RefereeListener.h"
#include "SoccerGame/Team/Team.h"
#include "SoccerGame/Player/Player.h"

#include "Strategy/Play/PlayFinder.h"
#include "Strategy/Play/Play.h"
#include "Strategy/Role.h"

#include "Strategy/Play/Playbook/Offense.h"

#include "Logger/Logging.h"

class PlayEngine : public RefereeListener
{
public:
    PlayEngine();
    ~PlayEngine();

    bool isDone();

    void update(Team *iTeam);
protected:
    virtual void gameStarted();
    virtual void gamePaused();
    virtual void gameEnded();

    std::vector<Play*> mAvailablePlays;
private:
    void assignRoles(Team* iTeam);
    void findNextPlay();
    void switchPlays(Play *newPlay);
    void updateRoles();

    void onGameStarted();
    void onGamePaused();
    void onGameEnded();

    //PlayFinder mPlayFinder;
    Play *mCurrentPlay;

    bool isGameEnded;
};

#endif // PLAYENGINE_H

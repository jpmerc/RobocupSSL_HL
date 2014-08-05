#ifndef PLAY_H
#define PLAY_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/ScoreGameSituation.h"

#include "SoccerGame/Player/Player.h"

class Play //: public ScoreGameSituation
{
public:
    virtual ~Play(){}

    //Play* getRequestedPlay() const;

    //void update();

    virtual bool isDone() = 0;
    virtual void update() = 0;
    virtual void reset() = 0;
    virtual int scoreCurrentSituation() = 0;
    virtual int getRoleSize()= 0;
    virtual void assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers) = 0;
protected:

    virtual void requestPlay() = 0;
    //virtual void findNextTactics();
    //virtual void updateTactics();
    virtual void createRoles() = 0;
    virtual Role* getRole(int iId) = 0;

    //void switchTactics(Tactic *oldTactic, Tactic *newTactic);

    TacticFinder tacticFinder;

    Play *mRequestedPlay;
    std::vector<Tactic*> mCurrentTactics;
    std::vector<Tactic*> mAvailableTactics;
    std::vector<Role*> mAvailableRoles;
};

#endif // PLAY_H

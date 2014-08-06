#ifndef PLAY_H
#define PLAY_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/ScoreGameSituation.h"

#include "SoccerGame/Player/Player.h"

class Play
{
public:
    virtual ~Play(){}

    virtual bool isDone() = 0;
    virtual void update(std::map<PlayerId, Player*> iPlayers) = 0;
    virtual void reset() = 0;
    virtual int scoreCurrentSituation() = 0;
    virtual int getRoleSize()= 0;
protected:

    virtual void requestPlay() = 0;
    virtual void createRoles() = 0;
    virtual Role* getRole(int iId) = 0;
    virtual void assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers) = 0;


    std::vector<Role*> mAvailableRoles;
};

#endif // PLAY_H

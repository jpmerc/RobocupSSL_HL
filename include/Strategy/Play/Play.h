#ifndef PLAY_H
#define PLAY_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/ScoreGameSituation.h"

#include "SoccerGame/Exception/RobocupException.h"

#include "SoccerGame/Player/Player.h"

class Play
{
public:
    virtual ~Play(){}

    virtual bool isDone() = 0;
    virtual void update(std::map<PlayerId, Player*> iPlayers) = 0;
    virtual void reset();
    virtual int getRoleSize();
protected:

    virtual void requestPlay() = 0;
    virtual void createRoles() = 0;
    virtual Role* getRole(int iId);
    virtual void assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers) = 0;


    std::vector<Role*> mAvailableRoles;
};

inline int Play::getRoleSize(){
    return mAvailableRoles.size();
}

#endif // PLAY_H

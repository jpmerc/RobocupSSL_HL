#ifndef PLAY_H
#define PLAY_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <string>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Tactic/Goalie.h"
#include "Strategy/ScoreGameSituation.h"

#include "SoccerGame/Exception/RobocupException.h"

#include "SoccerGame/Player/Player.h"

class Play
{
public:
    Play();
    virtual ~Play(){}

    virtual bool isDone() = 0;
    virtual void update(std::vector<PlayerId> iPlayers, TeamId iTeam) = 0;
    virtual void reset();
    virtual int getRoleSize();
    virtual std::pair<Tactic *, ParameterStruct> getPlayerTactic(PlayerId iPlayer);
    std::pair<Tactic*,ParameterStruct> getGoalieTactic();
protected:

    virtual void requestPlay() = 0;
    virtual void createRoles() = 0;
    virtual Role* getRole(int iId);
    virtual void assignRoleToPlayers(std::vector<PlayerId> iPlayers, TeamId iTeam);


    std::vector<Role*> mAvailableRoles;
    Role* mGoalieRole;
};

inline int Play::getRoleSize(){
    return mAvailableRoles.size();
}

#endif // PLAY_H

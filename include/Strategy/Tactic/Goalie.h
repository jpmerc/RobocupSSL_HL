#ifndef GOALIE_H
#define GOALIE_H

#include "Logger/Logging.h"
#include "Strategy/Tactic/Tactic.h"

class Goalie: public Tactic{
public:
    using Tactic::Tactic;
    Goalie();

    virtual std::pair<SkillStateMachine *, ParameterStruct> update(ParameterStruct iParam);

    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam);

    virtual bool isDone();
};

#endif // GOALIE_H

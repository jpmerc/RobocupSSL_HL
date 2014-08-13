#ifndef GOALIE_H
#define GOALIE_H

#include "Logger/Logging.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Skill/DriveToTarget.h"
#include "Strategy/Skill/DriveToPosition.h"
#include "Strategy/GameEvaluator.h"

class Goalie: public Tactic{
public:
    Goalie();

    virtual std::pair<SkillStateMachine *, ParameterStruct> update(ParameterStruct iParam);

    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam);

    virtual bool isDone();
};

#endif // GOALIE_H

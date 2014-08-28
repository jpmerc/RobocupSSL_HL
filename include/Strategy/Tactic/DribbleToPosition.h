#ifndef DRIBBLETOPOSITION_H
#define DRIBBLETOPOSITION_H

#include "Logger/Logging.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/AIConstants.hpp"
#include "Strategy/GameEvaluator.h"
#include "Utils/Line.h"

class DribbleToPosition: public Tactic{
public:
    using Tactic::Tactic;
    DribbleToPosition();

    virtual std::pair<SkillStateMachine *, ParameterStruct> update(ParameterStruct iParam);

    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam);

    virtual bool isDone();
};

#endif // DRIBBLETOPOSITION_H

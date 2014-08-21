#ifndef DRIBBLETOPOSITION_H
#define DRIBBLETOPOSITION_H

#include "Logger/Logging.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Skill/DriveToTarget.h"
#include "Strategy/Skill/DriveToPosition.h"
#include "Strategy/Skill/DefendGoal.h"
#include "Strategy/Skill/DriveToBall.h"
#include "Strategy/GameEvaluator.h"

class DribbleToPosition: public Tactic{
public:
    DribbleToPosition();

    virtual std::pair<SkillStateMachine *, ParameterStruct> update(ParameterStruct iParam);

    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam);

    virtual bool isDone();
};

#endif // DRIBBLETOPOSITION_H

#ifndef TACTIC_H
#define TACTIC_H

#include "Logger/Logging.h"
#include "Strategy/ParameterStruct.h"
#include "Strategy/Skill/SkillStateMachine.h"

class Tactic
{
public:
    Tactic(){}

    virtual std::pair<SkillStateMachine*,ParameterStruct> update(ParameterStruct iParam) = 0;

    virtual bool isDone() = 0;
    
    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam)= 0;
    
protected:
    SkillStateMachine* mActualSSM;
    std::vector<SkillStateMachine*> mSkillList;

};

#endif // TACTIC_H

#ifndef TACTIC_H
#define TACTIC_H

#include "Logger/Logging.h"
#include "Strategy/Skill/DefendGoal.h"
#include "Strategy/Skill/DriveToBall.h"
#include "Strategy/Skill/DriveToPosition.h"
#include "Strategy/Skill/DriveToTarget.h"
#include "Strategy/Skill/TestSkill.h"

class ParameterStruct;

class Line;

class Tactic
{
public:
    Tactic();

    virtual std::pair<SkillStateMachine*,ParameterStruct> update(ParameterStruct iParam) = 0;

    virtual bool isDone() = 0;
    
    virtual PlayerId getBestPlayer(TeamId iTeam,std::vector<PlayerId>& iPlayers,ParameterStruct iParam)= 0;
    
protected:

    enum class state : int{
        DEFEND_GOAL=0,
        DRIVE_TO_BALL=1,
        DRIVE_TO_POSITION=2,
        DRIVE_TO_TARGET=3,
    };

    void setState(state iState);
    bool stateEqual(state iState);

    SkillStateMachine* mActualSSM;
    std::vector<SkillStateMachine*> mSkillList;

};

inline Tactic::Tactic(){
    mSkillList.push_back(new DefendGoal);
    mSkillList.push_back(new DriveToBall);
    mSkillList.push_back(new DriveToPosition);
    mSkillList.push_back(new DriveToTarget);
    //mSkillList.push_back(new Test);
}

inline void Tactic::setState(state iState){
    mActualSSM = mSkillList[int(iState)];
}

inline bool Tactic::stateEqual(state iState){
    return mActualSSM == mSkillList[int(iState)];
}

#endif // TACTIC_H

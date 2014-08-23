#include "Strategy/Skill/SkillStateMachine.h"

SkillStateMachine::SkillStateMachine():mTerminated(false){
    mCurrentSkill = new Stop();
}



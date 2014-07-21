#ifndef ROLE_H
#define ROLE_H

#include "Strategy/Tactic/Tactic.h"
#include "Strategy/ParameterStruct.h"

#include "Logger/Logging.h"

#include <vector>

class Role{
public:
    Role(std::vector<std::pair <Tactic*,ParameterStruct>> iTacticVector,int iRoleId);
    void resetTactics(std::vector<std::pair<Tactic *, ParameterStruct> > iTacticVector);
    std::pair<Tactic *, ParameterStruct> getCurrentTactic();
    void incrementTactic();

private:
    int mRoleId;
    int mCurrentTactic;
    std::vector<std::pair<Tactic *, ParameterStruct> > mTactics;
};

inline std::pair<Tactic *, ParameterStruct>  Role::getCurrentTactic(){
    return mTactics[mCurrentTactic];
}

#endif

#ifndef ROLE_H
#define ROLE_H

#include "Strategy/Tactic/Tactic.h"

#include "Logger/Logging.h"

#include <vector>

class Role{
public:
    Role(std::vector<Tactic*> iTacticVector,int iRoleId);
    void resetTactics(std::vector<Tactic*> iTacticVector);
    Tactic * getCurrentTactic();
    void incrementTactic();

private:
    int mRoleId;
    int mCurrentTactic;
    std::vector<Tactic*> mTactics;
};

inline Tactic * Role::getCurrentTactic(){
    return mTactics[mCurrentTactic];
}

#endif

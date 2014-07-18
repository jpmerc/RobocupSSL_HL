#ifndef ROLE_H
#define ROLE_H

#include "Strategy/Tactic/Tactic.h"

#include <vector>

class Role{
public:
    Role(std::vector<Tactic*> iTacticVector,int iRoleId);

    void resetTactics(std::vector<Tactic*> iTacticVector);

    Tactic * getCurrentTactic();
    void setCurrentTactic(int iCurrentTactic);
private:
    int mRoleId;
    int mCurrentTactic;
    std::vector<Tactic*> mTactics;
};

inline void Role::setCurrentTactic(int iCurrentTactic){
    //add condition
    mCurrentTactic = iCurrentTactic;
}

inline Tactic * Role::getCurrentTactic(){
    return mTactics[mCurrentTactic];
}

#endif

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
    void assignTacticToPlayer(std::vector<PlayerId>& iPlayers);
    void incrementTactic();
    void setAssignation(bool iIsAssigned);
    bool isAssigned();
    int getId();
    PlayerId getCurrentPlayer();

private:
    int mRoleId;
    PlayerId mCurrentPlayer;
    bool mIsAssigned;
    int mCurrentTactic; //iterator TODO
    std::vector<std::pair<Tactic *, ParameterStruct> > mTactics;
};

inline std::pair<Tactic *, ParameterStruct>  Role::getCurrentTactic(){
    return mTactics[mCurrentTactic];
}

inline void Role::setAssignation(bool iIsAssigned){
    mIsAssigned = iIsAssigned;
}

inline bool Role::isAssigned(){
    return mIsAssigned;
}

inline int Role::getId(){
    return mRoleId;
}

inline PlayerId Role::getCurrentPlayer(){
    return mCurrentPlayer;
}

#endif

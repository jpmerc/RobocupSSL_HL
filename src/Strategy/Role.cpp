#include "Strategy/Role.h"


Role::Role(std::vector<Tactic*> iTacticVector,int iRoleId):mTactics(iTacticVector),mRoleId(iRoleId),mCurrentTactic(0){

}

void Role::resetTactics(std::vector<Tactic*> iTacticVector){
    mCurrentTactic = 0;
    mTactics = iTacticVector;
}

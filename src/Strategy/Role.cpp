#include "Strategy/Role.h"


Role::Role(std::vector<std::pair<Tactic *, ParameterStruct> > iTacticVector, int iRoleId):mTactics(iTacticVector),mRoleId(iRoleId),mCurrentTactic(0){

}

void Role::resetTactics(std::vector<std::pair<Tactic *, ParameterStruct> >  iTacticVector){
    mCurrentTactic = 0;
    mTactics = iTacticVector;
}

void Role::incrementTactic(){
    int totalTactics = mTactics.size();
    if(mCurrentTactic < totalTactics){
        mCurrentTactic ++;
    }
}

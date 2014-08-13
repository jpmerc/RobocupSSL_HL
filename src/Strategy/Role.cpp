#include "Strategy/Role.h"


Role::Role(std::vector<std::pair<Tactic *, ParameterStruct> > iTacticVector, int iRoleId):
    mTactics(iTacticVector),mRoleId(iRoleId),mCurrentTactic(0),mIsAssigned(false),mCurrentPlayer(0){  //default player id?

}

void Role::resetTactics(std::vector<std::pair<Tactic *, ParameterStruct> >  iTacticVector){
    mCurrentTactic = 0;
    mTactics = iTacticVector;
}

void Role::assignTacticToPlayer(std::vector<PlayerId>& iPlayers,TeamId iTeam){
    ParameterStruct lParam = mTactics[mCurrentTactic].second;
    mCurrentPlayer = mTactics[mCurrentTactic].first->getBestPlayer(iTeam,iPlayers,lParam);
    lParam.playerId = mCurrentPlayer;
    lParam.teamId = iTeam;
    INFO << "Player :" << mCurrentPlayer.getValue() << "Get Role " << mRoleId;
    mIsAssigned = true;
}

void Role::incrementTactic(){
    int totalTactics = mTactics.size();
    if(mCurrentTactic < totalTactics){
        mCurrentTactic ++;
    }
}

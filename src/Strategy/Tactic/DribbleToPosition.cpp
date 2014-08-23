#include "Strategy/Tactic/DribbleToPosition.h"

DribbleToPosition::DribbleToPosition(){
    INFO << "Create DribbleToPosition Tactic";
    mSkillList.push_back(new DriveToBall());
    mSkillList.push_back(new DriveToPosition());
    mActualSSM = mSkillList[0];
}

std::pair<SkillStateMachine*,ParameterStruct> DribbleToPosition::update(ParameterStruct iParam){
    // add enum for states in tactic
    // make isDone logical operation so no reset needed
    // system de score avec hysteresis
    if(mActualSSM == mSkillList[0] && mActualSSM->isDone() || mActualSSM == mSkillList[1]){
        mActualSSM = mSkillList[1];
        Line lLine = GameEvaluator::getLineBetweenBallAndCoord(Vector2d(1600,-1000));
        Vector2d lCoord = lLine.getCoordOnLine(-lLine.length() - 50);
        INFO << "HAA whatt " << lCoord.x << ' ' << lCoord.y;
        iParam.positionTarget = Pose(lCoord,0);
        iParam.canDrible = true;
    }
    if(mActualSSM == mSkillList[1] && mActualSSM->isDone()){
        mSkillList[1] = new DriveToPosition();
        mActualSSM = mSkillList[1];
        iParam.positionTarget = Pose(1600,-1000,0);
    }
    double lDistance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,
                                                                         iParam.teamId,
                                                                         GameEvaluator::getBallPose().Position);
    if(lDistance > 400){
        mSkillList[0] = new DriveToBall();
        mActualSSM = mSkillList[0];
    }

    std::pair<SkillStateMachine*,ParameterStruct> skillSet(mActualSSM,iParam);
    return skillSet;
}

PlayerId DribbleToPosition::getBestPlayer(TeamId iTeam, std::vector<PlayerId>& iPlayers, ParameterStruct iParam){

    PlayerId lPlayerId = GameEvaluator::getClosestPlayer(iPlayers,iTeam,GameEvaluator::getBallPose().Position);
    return lPlayerId;
}

bool DribbleToPosition::isDone(){

}

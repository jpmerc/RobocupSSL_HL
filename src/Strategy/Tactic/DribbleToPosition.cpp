#include "Strategy/Tactic/DribbleToPosition.h"

DribbleToPosition::DribbleToPosition(){
    INFO << "Create DribbleToPosition Tactic";
    this->setState(state::DRIVE_TO_BALL);
}

std::pair<SkillStateMachine*,ParameterStruct> DribbleToPosition::update(ParameterStruct iParam){
    // make isDone logical operation so no reset needed
    // system de score avec hysteresis
    if(this->stateEqual(state::DRIVE_TO_BALL) &&
            mActualSSM->isDone() ||
            this->stateEqual(state::DRIVE_TO_POSITION)){
        this->setState(state::DRIVE_TO_POSITION);
        Line lLine = GameEvaluator::getLineBetweenBallAndCoord(Vector2d(1600,-1000));
        Vector2d lCoord = lLine.getCoordOnLine(-lLine.length() - 50);
        INFO << "HAA whatt " << lCoord.x << ' ' << lCoord.y;
        iParam.positionTarget = Pose(lCoord,0);
        iParam.canDrible = true;
    }
    if(this->stateEqual(state::DRIVE_TO_POSITION) &&
            mActualSSM->isDone()){
        //reset
        this->setState(state::DRIVE_TO_POSITION);
        iParam.positionTarget = Pose(1600,-1000,0);
    }
    double lDistance = GameEvaluator::getDistanceBetweenPlayerAndCoord(iParam.playerId,
                                                                         iParam.teamId,
                                                                         GameEvaluator::getBallPose().Position);
    if(lDistance > 400){
        this->setState(state::DRIVE_TO_BALL);
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

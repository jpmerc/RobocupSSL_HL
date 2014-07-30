#include "SoccerGame/Player/Player.h"

#include <queue>

Player::Player(const PlayerId &iPlayerId,
    const TeamId &iTeamId,
    Navigator *iNavigator,
    Pose iPose,
    Vector2d iVelocity) :
    mTeamId(iTeamId),
    mId(iPlayerId),
    mActualCommand(Velocity::ZERO),mPoseGoalToReach(Pose::ZERO),
    mNavigator(iNavigator)
{
    mPose = iPose;
    mVelocity = iVelocity;
    mRole = NULL; //runtime assignation
}

void Player::move(){
    Vector2d lPositionCommand = Vector2d::ZERO;
    Orientation lOrientationCommand = Orientation::ZERO;
    mNavigator->setActualPose(mPose);
    mNavigator->setGoalPose(mPoseGoalToReach);
    lPositionCommand = mNavigator->calculateNewVector();
    if(!mNavigator->isAngleGoalReached()){
        lOrientationCommand = mNavigator->calculateNewOrientation();
    }

    Pose lCommand(lPositionCommand,lOrientationCommand);

    if(lCommand == Pose::ZERO){
        this->updateGoal();
    }

    lCommand = lCommand.fromGlobalToRelative(mPose.Angle.getPolar());
    mActualCommand.velocity = lCommand;

}

//----Strategy FUNCTION ----

std::pair<Tactic *, ParameterStruct> Player::getTactic(){
    std::pair<Tactic *, ParameterStruct> lTactic = mRole->getCurrentTactic();
    lTactic.second.teamId = this->getTeamId();
    lTactic.second.playerId = this->getId();
    return lTactic;
}


//-----PATH FUNCTION-----

void Player::clearPath(){
    while(!this->mPath.empty()) this->mPath.pop();
}

void Player::addVectorToPath(Pose iPosition){
    this->mPath.push(iPosition);
}

void Player::refreshPath(std::queue<Pose> iNewPath){
    this->clearPath();
    while(!iNewPath.empty()){
        this->mPath.push(iNewPath.front());
        iNewPath.pop();
    }
    this->updateGoal();
}

void Player::updateGoal(){

    if(!pathIsEmpty()){
        this->mPoseGoalToReach = this->mPath.front();
        this->mPath.pop();
    }
}

bool Player::pathIsEmpty(){
    if(mPath.empty()){
        return true;
    }
    else{
        return false;
    }
}

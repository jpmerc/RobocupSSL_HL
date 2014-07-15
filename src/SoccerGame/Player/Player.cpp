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

    Velocity lCommand(lPositionCommand,lOrientationCommand);

    if(lCommand == Velocity::ZERO){
        this->updateGoal();
    }

    lCommand = lCommand.fromGlobalToRelative(mPose.Angle.getPolar());
    mActualCommand = lCommand;

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

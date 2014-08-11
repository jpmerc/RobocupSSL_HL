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
    Vector2d lSpeedCommand = Vector2d::ZERO;
    Orientation lOrientationCommand = Orientation::ZERO;

    mNavigator->setActualPose(mPose);
    mNavigator->setGoalPose(mPoseGoalToReach);
    lSpeedCommand = mNavigator->calculateNewVector();
    if(!mNavigator->isAngleGoalReached()){
        //lOrientationCommand = mNavigator->calculateNewOrientation();
        lOrientationCommand = Orientation::ZERO;
    }

    INFO << "Player " << this->getTeamId().getValue() << " " << this->getId().getValue();
    INFO << "Command!!: " << lSpeedCommand.x << " " << lSpeedCommand.y;
    Pose lCommand(lSpeedCommand,lOrientationCommand);

    if(lCommand == Pose::ZERO){
        this->updateGoal();
    }

    lCommand = lCommand.fromGlobalToRelative(mPose.Angle.getPolar());
    mActualCommand.velocity = lCommand;

}

//-----PATH FUNCTION-----


Geometry2d::Circle* Player::getShape(){
    return new Geometry2d::Circle(this->getPosition(),
                                  Robot_Radius);
}

void Player::clearPath(){
    while(!this->mPath.empty()) this->mPath.pop();
}

void Player::addVectorToPath(Pose iPosition){
    this->mPath.push(iPosition);
}

void Player::refreshPath(Planning::Path &iNewPath){
    this->clearPath();
    for(int i = 0; i < iNewPath.points.size(); i++){
        // TODO add a way orientation when the pathfinder support Orientation
        // Switch everything to Vector2f
        Vector2f e = iNewPath.points.at(i);
        Vector2d d(e.x, e.y);
        Pose p(d, 0, 1);
        this->mPath.push(p);
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


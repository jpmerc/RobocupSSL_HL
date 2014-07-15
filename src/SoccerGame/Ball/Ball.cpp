#include "SoccerGame/Ball/Ball.h"

Ball::Ball(const BallId &iId,
    Pose iPose,
    Vector2d iVelocity
    )
    : mId(iId){
    mPose = iPose;
    mVelocity = iVelocity;
}

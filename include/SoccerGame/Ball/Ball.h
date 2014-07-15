/****************************************************************************
 *Author : Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose: This module represents a ball of the soccer game
 *
 ****************************************************************************/

#ifndef BALL_H_
#define BALL_H_

#include "Utils/Vector2d.h"

#include "SoccerGame/MovableObject.h"
#include "SoccerGame/Ball/BallId.h"

class Ball : public MovableObject {
public:
    Ball(
        const BallId &iId,
        Pose iPose = Pose::ZERO,
        Vector2d iVelocity = Vector2d::ZERO
    );

    bool operator==(const Ball& other) const;

private:
    BallId mId;
};

inline bool Ball::operator==(const Ball& other) const {
    return mId == other.mId;
}
#endif

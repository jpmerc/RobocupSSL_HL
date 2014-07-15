#ifndef BALL_MOCK_H
#define BALL_MOCK_H

#include <gmock/gmock.h>

#include "SoccerGame/Ball/Ball.h"
#include "Utils/Vector2d.h"

class BallMock : public Ball{
public:
    BallMock(const BallId &iId) : Ball(iId){}

    MOCK_METHOD0(getPosition, Vector2d());
    MOCK_METHOD1(setPosition, void(Vector2d iPosition));
    MOCK_METHOD0(getOrientation, Orientation());
    MOCK_METHOD1(setOrientation, void(Orientation iOrientation));
    MOCK_METHOD0(getVelocity, Vector2d());
    MOCK_METHOD1(setVelocity, void(Vector2d iVelocity));
};

#endif

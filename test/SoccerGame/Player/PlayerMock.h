#ifndef PLAYERMOCK_H_
#define PLAYERMOCK_H_

#include <gmock/gmock.h>

#include "SoccerGame/Player/Player.h"


class PlayerMock : public Player {
public:
    PlayerMock(
            const PlayerId &iPlayerId,
            const TeamId &iTeamId,
            Navigator *iNavigator = NULL,
            Pose iPose = Pose::ZERO,
            Vector2d iVelocity = Vector2d::ZERO
            ) : Player(iPlayerId, iTeamId,iNavigator, iPose, iVelocity){}

    MOCK_METHOD0(getId, void());
    MOCK_METHOD0(getPosition, Vector2d());
    MOCK_METHOD1(setPosition, void(Vector2d iPosition));
    MOCK_METHOD0(getOrientation, Orientation());
    MOCK_METHOD1(setOrientation, void(Orientation iOrientation));
    MOCK_METHOD0(getVelocity, Vector2d());
    MOCK_METHOD1(setVelocity, void(Vector2d iVelocity));
};

#endif

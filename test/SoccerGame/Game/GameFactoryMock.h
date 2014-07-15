#ifndef GAME_FACTORY_MOCK_H
#define GAME_FACTORY_MOCK_H

#include <gmock/gmock.h>

#include "SoccerGame/Game/GameFactory.h"

class GameFactoryMock : public GameFactory{
public:
    MOCK_METHOD2(createGame, Game*(Ball *iBall, Field *iField));
    MOCK_METHOD4(createField, Field*(
                     double iWidth,
                     double iHeight,
                     double iPlayableWidth,
                     double iPlayableHeight
                ));
    MOCK_METHOD1(createTeam, Team*(TeamId iTeamId));
    MOCK_METHOD2(createPlayer, Player*(PlayerId iPlayerId, TeamId iTeamId));
    MOCK_METHOD0(createBall, Ball*());
};

#endif

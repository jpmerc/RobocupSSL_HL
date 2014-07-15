#ifndef GAME_MOCK_H
#define GAME_MOCK_H

#include <gmock/gmock.h>

#include "SoccerGame/Game/Game.h"

class GameMock : public Game{
public:
    GameMock(Ball *iBall, Field *iField) : Game(iBall, iField){}
};

#endif

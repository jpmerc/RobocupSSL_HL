/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is responsible to create a consistent instance of a game.
 *
 ****************************************************************************/
#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include "SoccerGame/Game/Game.h"
#include "SoccerGame/Field/Field.h"
#include "SoccerGame/Team/Team.h"
#include "SoccerGame/Team/TeamId.h"
#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Ball/Ball.h"
#include "Control/Navigator.h"

struct GameFactory{
    virtual Game* createGame(Ball *iBall, Field *iField, Referee *iRef) const;
    virtual Field* createField(
            double iWidth = 0,
            double iHeight = 0,
            double iPlayableWidth = 0,
            double iPlayableHeight = 0
    ) const;
    virtual Team* createTeam(TeamId iTeamId) const;
    virtual Player* createPlayer(PlayerId iPlayerId, TeamId iTeamId, Navigator *iNavigator) const;
    virtual Ball* createBall(BallId iBallId) const;
    virtual Referee* createRef() const;

};

#endif

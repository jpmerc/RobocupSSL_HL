/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module describes a complete game with the different teams,
 *          the field, the ball, etc.
 *
 ****************************************************************************/
#ifndef GAME_H
#define GAME_H

#include <map>

#include "SoccerGame/Field/Field.h"
#include "SoccerGame/Team/Team.h"
#include "SoccerGame/Ball/Ball.h"

class Game{
public:
    Game(Ball* iBall, Field* iField);
    ~Game();

    Ball* getBall() const;
    Field* getField() const;

    std::map<TeamId, Team*> getTeams() const;
    bool addTeam(Team* iTeam);

private:
    void tearDownTeams();

    Field* mField;
    std::map<TeamId, Team*> mTeams;
    Ball* mBall;
    typedef std::pair<TeamId, Team*> mTeamsPair;
};

#endif

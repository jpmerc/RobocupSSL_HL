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
#include "SoccerGame/Referee/Referee.h"
#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"

class Game{
public:
    Game(Ball* iBall, Field* iField, Referee *iRef);
    ~Game();

    Ball* getBall() const;
    Field* getField() const;
    Referee* getRef() const;

    std::map<TeamId, Team*> getTeams() const;
    bool addTeam(Team* iTeam);
    void unwrapPackets(SSL_Referee* iRefPacket,SSL_WrapperPacket* iWrapperPacket);

private:
    void tearDownTeams();

    Field* mField;
    std::map<TeamId, Team*> mTeams;
    Ball* mBall;
    Referee* mRef;
    typedef std::pair<TeamId, Team*> mTeamsPair;
};

inline Referee* Game::getRef() const{
    return mRef;
}

#endif

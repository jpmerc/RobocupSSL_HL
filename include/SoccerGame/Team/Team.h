/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module describes a team of the game.
 *          It contains players.
 *
 ****************************************************************************/
#ifndef TEAM_H
#define TEAM_H

#include "TeamId.h"

#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Player/PlayerId.h"
#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"

#include <map>

class Team {
public:
    Team(const TeamId &iId);

    TeamId getId() const;

    bool addPlayer(Player* iPlayer);

    std::map<PlayerId, Player*> getPlayers() const;

    bool hasPlayer(PlayerId iPlayerId) const;

    void updatePlayersPositions(const std::map<PlayerId, Pose> &iPositions);

    void setPlayersPositions(const google::protobuf::RepeatedPtrField< SSL_DetectionRobot >& iPositions);

    std::map<PlayerId, Pose> getPlayersPosition() const;

private:
    Player* findPlayerByID(PlayerId iPlayerId) const;

    TeamId mId;

    std::map<PlayerId, Player*> mPlayers;

    typedef std::pair<PlayerId, Player*> mPlayersPair;

};

inline TeamId Team::getId() const {
    return mId;
}

#endif

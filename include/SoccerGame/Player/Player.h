/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is a representation of a player (robot) in the game
 *          It contains a role, a goal and a path to accomplish this goal.
 *
 ****************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "SoccerGame/MovableObject.h"

#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"
#include "Utils/Orientation.h"
#include "Utils/Vector2d.h"
#include "Utils/Pose.h"
#include "Utils/Velocity.h"
#include "Control/Navigator.h"

class Player :  public MovableObject{
public:
    Player(const PlayerId &iPlayerId,
        const TeamId &iTeamId,
        Navigator *iNavigator = NULL,
        Pose iPose = Pose::ZERO,
        Vector2d iVelocity = Vector2d::ZERO);

    PlayerId getId() const;
    Pose getPoseToReach() const;
    void setCommand(Velocity iPose);
    Velocity getCommand() const;

    void move();

    //---Path----
    void clearPath();
    void addVectorToPath(Pose iPosition);
    void refreshPath(std::queue<Pose> iNewPath);
    void updateGoal();
    bool pathIsEmpty();

    bool operator==(const Player& other) const;

private:
    PlayerId mId;
    TeamId mTeamId;
    std::queue<Pose> mPath;
    Pose mPoseGoalToReach;
    Velocity mActualCommand;
    Navigator* mNavigator;
};

inline PlayerId Player::getId() const {
    return mId;
}

inline bool Player::operator==(const Player& other) const {
    return mId == other.mId;
}

inline Pose Player::getPoseToReach()const{
    return mPoseGoalToReach;
}

inline void Player::setCommand(Velocity iPose){
    mActualCommand = iPose;
}

inline Velocity Player::getCommand() const{
    return mActualCommand;
}
#endif

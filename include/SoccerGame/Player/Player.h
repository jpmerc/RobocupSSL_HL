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

#include "Pathfinder/RRTPlanner.hpp"
#include "Utils/Geometry2d/CompositeShape.hpp"
#include "Utils/Geometry2d/Circle.hpp"

#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"
#include "Utils/Orientation.h"
#include "Utils/Vector2d.h"
#include "Utils/Pose.h"
#include "Utils/Velocity.h"
#include "Control/Navigator.h"
#include "Strategy/CommandStruct.h"

class Role;

class Player :  public MovableObject{
public:
    Player(const PlayerId &iPlayerId,
        const TeamId &iTeamId,
        Navigator *iNavigator = NULL,
        Pose iPose = Pose::ZERO,
        Vector2d iVelocity = Vector2d::ZERO);

    PlayerId getId() const;
    TeamId getTeamId() const;
    Pose getPoseToReach() const;
    void setCommand(CommandStruct iCommand);
    void setSpeedCommand(Pose iCommand);
    CommandStruct getCommand() const;

    void move();

    //---Path----
    Geometry2d::Circle* getShape();
    void clearPath();
    void addVectorToPath(Pose iPosition);
    void refreshPath(Planning::Path &iNewPath);
    void updateGoal();
    bool pathIsEmpty();

    bool operator==(const Player& other) const;

private:
    PlayerId mId;
    TeamId mTeamId;
    std::queue<Pose> mPath;
    Pose mPoseGoalToReach;
    CommandStruct mActualCommand;
    Navigator* mNavigator;
};

inline PlayerId Player::getId() const {
    return mId;
}

inline TeamId Player::getTeamId() const{
    return mTeamId;
}

inline bool Player::operator==(const Player& other) const {
    return mId == other.mId;
}

inline Pose Player::getPoseToReach()const{
    return mPoseGoalToReach;
}

inline void Player::setCommand(CommandStruct iCommand){
    iCommand.playerId = mId;
    mActualCommand = iCommand;
}

inline void Player::setSpeedCommand(Pose iCommand){
   mActualCommand.velocity = iCommand;
}

inline CommandStruct Player::getCommand() const{
    return mActualCommand;
}

#endif

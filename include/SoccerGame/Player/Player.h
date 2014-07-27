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

#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"
#include "Utils/Orientation.h"
#include "Utils/Vector2d.h"
#include "Utils/Pose.h"
#include "Utils/Velocity.h"
#include "Control/Navigator.h"
#include "Strategy/Role.h"

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
    void setCommand(Velocity iPose);
    Velocity getCommand() const;

    void move();

    //---IA---
    void setRole(Role *iRole);
    bool haveRole();
    std::pair<Tactic *, ParameterStruct> getTactic();

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
    Role* mRole;
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

inline void Player::setCommand(Velocity iPose){
    mActualCommand = iPose;
}

inline Velocity Player::getCommand() const{
    return mActualCommand;
}

inline void Player::setRole(Role *iRole){
    mRole = iRole;
}

inline bool Player::haveRole(){
    if(mRole){
        return true;
    }
    else
        return false;
}

#endif

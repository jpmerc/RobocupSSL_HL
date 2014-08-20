#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Pathfinder/RRTPlanner.hpp"
#include "Utils/Vector2d.h"
#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Ball/Ball.h"
#include <boost/ptr_container/ptr_map.hpp>

#include <string>
#include <queue>
#include <vector>


class Pathfinder{
public:
    Pathfinder();
    virtual ~Pathfinder();

    virtual void addObstacle(Geometry2d::Shape &iObstacle);
    void addPlayer(Player *iPlayer);

    virtual Planning::Path findPath(const Player *iPlayer, Pose iGoal);

protected:
    std::vector<Player*> mPlayers;
    Geometry2d::CompositeShape mObstacles; // These are the obstacle that are not player for Debugging
private:
    Geometry2d::Circle fromPlayerGetShape(const Player &iPlayer);
    Geometry2d::CompositeShape getCollisionShapeOfOtherPlayer(const Player *iPlayer);
};

#endif

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Pathfinder/RRTPlanner.hpp"
#include "Utils/Vector2d.h"
#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Ball/Ball.h"

#include <queue>
#include <vector>
class Pathfinder{
public:
    Pathfinder();
    virtual ~Pathfinder();

    virtual bool addObstacle(const Player &iObstacle);

    virtual Planning::Path findPath(Pose iStart, Pose iGoal);

protected:
    //std::vector<Player> mObstacles;
    Geometry2d::CompositeShape mObstacles;
private:
    Geometry2d::Circle fromPlayerGetShape(const Player &iPlayer);

    Planning::RRTPlanner mPathGenerator;
};

#endif

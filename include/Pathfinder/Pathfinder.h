#ifndef PATHFINDER_H
#define PATHFINDER_H

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

    virtual std::queue<Pose> findPath(Pose iStart, Pose iGoal);

protected:
    std::vector<Player> mObstacles;
};

#endif

#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "Utils/Vector2d.h"
#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Ball/Ball.h"

#include <queue>
#include <vector>

class Pathfinder{
public:
    Pathfinder(const Ball &iBall);
    virtual ~Pathfinder();

    virtual bool addObstacle(const Player &iObstacle);

    virtual std::queue<Vector2d> findPath(Vector2d iStart, Vector2d iGoal);

protected:
    std::vector<Player> mObstacles;
    Ball mBall;
};

#endif

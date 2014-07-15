#include "Pathfinder/Pathfinder.h"

#include <algorithm>

Pathfinder::Pathfinder(const Ball &iBall)
    : mBall(iBall){
}

Pathfinder::~Pathfinder(){
}

bool Pathfinder::addObstacle(const Player &iObstacle){
    if(std::find(mObstacles.begin(), mObstacles.end(), iObstacle) != mObstacles.end())
    {
        return false;
    }

    mObstacles.push_back(iObstacle);

    return true;
}

std::queue<Vector2d> Pathfinder::findPath(Vector2d iStart, Vector2d iGoal)
{
    //TODO: Define this method as pure virtual and implement a pathfinder
    std::queue<Vector2d> lPath;

    lPath.push(iGoal);

    return lPath;
}

#include "Pathfinder/Pathfinder.h"

#include <algorithm>

Pathfinder::Pathfinder(){
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

std::queue<Pose> Pathfinder::findPath(Pose iStart, Pose iGoal)
{
    //TODO: Define this method as pure virtual and implement a pathfinder
    std::queue<Pose> lPath;

    lPath.push(iGoal);

    return lPath;
}

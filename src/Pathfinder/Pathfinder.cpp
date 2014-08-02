#include "Pathfinder/Pathfinder.h"

#include <algorithm>

Pathfinder::Pathfinder(){
}

Pathfinder::~Pathfinder(){
}

bool Pathfinder::addObstacle(const Player &iObstacle){
    /*
    if(std::find(mObstacles.begin(), mObstacles.end(), iObstacle) != mObstacles.end())
    {
        return false;
    }*/
    Geometry2d::Circle shapeObstacle = this->fromPlayerGetShape(iObstacle);
    mObstacles.add(std::shared_ptr<Geometry2d::Shape>(&shapeObstacle));

    return true;
}

Geometry2d::Circle Pathfinder::fromPlayerGetShape(const Player &iPlayer){
    Geometry2d::Circle c(iPlayer.getPosition(),
                         Robot_Radius);
    return c;
}

Planning::Path Pathfinder::findPath(Pose iStart, Pose iGoal)
{
    //TODO: Define this method as pure virtual and implement a pathfinder
    Planning::Path lPath;

    //mPathGenerator.run();

    return lPath;
}

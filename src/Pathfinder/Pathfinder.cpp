#include "Pathfinder/Pathfinder.h"

#include <algorithm>

Pathfinder::Pathfinder(){
}

Pathfinder::~Pathfinder(){
}

void Pathfinder::addObstacle(Geometry2d::Shape &iObstacle){
    mObstacles.add(std::shared_ptr<Geometry2d::Shape>(&iObstacle));
}

void Pathfinder::addPlayer(Player *iPlayer){
    mPlayers.push_back(iPlayer);
}

Planning::Path Pathfinder::findPath(const Player *iPlayer, Pose iGoal){

    Geometry2d::CompositeShape lCompositeShape = this->getCollisionShapeOfOtherPlayer(iPlayer);

    Pose lStart = iPlayer->getPose();

    Planning::Path lPath;
    Planning::RRTPlanner lPatGenerator;
    lPatGenerator.run(lStart.Position,
                       lStart.Angle.getPolar(),
                       Vector2f::ZERO,
                       iGoal.Position,
                       &lCompositeShape,
                       lPath);
    //Let's delete the starting point (we dont need it)
    //lPath.points.erase(lPath.points.begin());
    return lPath;
}


Geometry2d::CompositeShape Pathfinder::getCollisionShapeOfOtherPlayer(const Player *iPlayerNotObstacle){
    Geometry2d::CompositeShape lCompositeShape;
    for(auto it = mPlayers.begin(); it != mPlayers.end(); ++it)
    {
        if(*it != iPlayerNotObstacle){
            Geometry2d::Circle* s = (*it)->getShape();
            lCompositeShape.add(s->getPointer());
        }
    }


    return lCompositeShape;
}

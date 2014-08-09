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
    std::cout<<"Here we asses player with id: "<<iPlayer->getUniqueId() <<std::endl;
    mPlayers[iPlayer->getUniqueId()] = iPlayer;
}



Planning::Path Pathfinder::findPath(const Player *iPlayer, Pose iGoal){

    Planning::Path lPath;
    Geometry2d::CompositeShape lCompositeShape = this->getCollisionShapeOfOtherPlayer(iPlayer->getUniqueId());

    Pose lStart = iPlayer->getPose();
    mPathGenerator.run(lStart.Position,
                       lStart.Angle.getPolar(),
                       Vector2f::ZERO,
                       iGoal.Position,
                       &lCompositeShape,
                       lPath);

    return lPath;
}


Geometry2d::CompositeShape Pathfinder::getCollisionShapeOfOtherPlayer(const std::string iPlayerId){
    Geometry2d::CompositeShape lCompositeShape;
    for(std::map<std::string, Player*>::iterator it = mPlayers.begin(); it != mPlayers.end(); ++it)
    {
        if(it->first != iPlayerId){
            Geometry2d::Circle* s = it->second->getShape();
            lCompositeShape.add(s->getPointer());
        }
    }


    return lCompositeShape;
}

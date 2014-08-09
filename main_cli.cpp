
#include "GUI/MainBox.h"
#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactory.h"

int main(int arc, char* argv[]) {
    PlayEngine *lPlayEngine = new PlayEngine;
    Navigator *lNavigator = new Navigator;
    Pathfinder *lPathfinder = new Pathfinder;
    /*
    Geometry2d::Circle c1(Vector2f(1,1), 0.17);
    Geometry2d::Circle c2(Vector2f(1,1.34), 0.17);
    Geometry2d::Circle c3(Vector2f(1,1.68), 0.17);
    Geometry2d::CompositeShape s;
    s.add(std::shared_ptr<Geometry2d::Shape>(&c1));
    s.add(std::shared_ptr<Geometry2d::Shape>(&c2));
    s.add(std::shared_ptr<Geometry2d::Shape>(&c3));

    Vector2f start(0.7,1.2);
    Vector2f end(1.3,0.8);

    Planning::RRTPlanner *iTree = new Planning::RRTPlanner();
    Planning::Path p;
    iTree->run(start, 1.0, Vector2f(0,0),end, &s,p);

    for(int i =0; i < p.points.size(); i++){
        std::cout << "["<<i<<"] "<< p.points[i].x << " " << p.points[i].y << std::endl;
    }*/

    SoccerGame lSoccerGame(lPlayEngine, lNavigator, lPathfinder);

    GameFactory lGameFactory;

    lSoccerGame.createSoccerGame(lGameFactory);

    lSoccerGame.startGame();

    return 0;
}

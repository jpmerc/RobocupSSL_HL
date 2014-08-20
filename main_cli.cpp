
#include "GUI/MainBox.h"
#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactory.h"

int main(int arc, char* argv[]) {
    PlayEngine *lPlayEngine = new PlayEngine;
    Navigator *lNavigator = new Navigator;
    Pathfinder *lPathfinder = new Pathfinder;

    //TODO Make unit test for pathfinder
    /*
    Pose obstacle1Pose(Vector2d(1000,0), Orientation::ZERO);
    Pose obstacle2Pose(Vector2d(1000,1000), Orientation::ZERO);
    Player *player = new Player(0, 0, lNavigator);
    Player *obstacle1 = new Player(1, 0, lNavigator, obstacle1Pose);
    Player *obstacle2 = new Player(1, 0, lNavigator, obstacle2Pose);

    lPathfinder->addPlayer(player);
    lPathfinder->addPlayer(obstacle1);
    lPathfinder->addPlayer(obstacle2);
    std::vector<Planning::Path> paths;
    for(int i = 0; i < 20; i++){//Number of starting positions
        player->setPosition(Vector2d(1200 + i*100, 0));

        //bool exitFlag = true;
        //for(int j = 0; j < 200 && exitFlag; j++){}
        std::cout << "OBSTACLE:"<< std::endl;
        lPathfinder->findPath(obstacle1, Pose::ZERO);
        lPathfinder->findPath(obstacle2, Pose::ZERO);
        std::cout << "PLAYER:"<< std::endl;
        Planning::Path lPath = lPathfinder->findPath(player, Pose::ZERO);
        paths.push_back(lPath);
    }
    // output:
    for(int j = 0; j < paths.size(); j++){
        for(int i = 0; i < paths[j].size(); i++){
            std::cout << paths[j].points[i].x << ", " << paths[j].points[i].y <<std::endl;
        }
    }*/

   SoccerGame lSoccerGame(lPlayEngine, lNavigator, lPathfinder);

   GameFactory lGameFactory;

   lSoccerGame.createSoccerGame(lGameFactory);

   lSoccerGame.startGame();

    return 0;
}


#include "GUI/MainBox.h"
#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactory.h"

int main(int arc, char* argv[]) {
    PlayEngine *lPlayEngine = new PlayEngine;
    Navigator *lNavigator = new Navigator;
    Pathfinder *lPathfinder = new Pathfinder;
    SoccerGame lSoccerGame(lPlayEngine, lNavigator, lPathfinder);

    GameFactory lGameFactory;

    lSoccerGame.createSoccerGame(lGameFactory);

    lSoccerGame.startGame();

    return 0;
}

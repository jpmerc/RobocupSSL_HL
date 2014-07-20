#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactory.h"

int main(int arc, char* argv[]) {
    PlayEngine *lPlayEngine = new PlayEngine;
    Navigator *lNavigator = new Navigator;
    SoccerGame lSoccerGame(lPlayEngine, lNavigator);

    GameFactory lGameFactory;

    lSoccerGame.createSoccerGame(lGameFactory);

    lSoccerGame.startGame();

    return 0;
}


#include "GUI/MainBox.h"
#include "SoccerGame/SoccerGame.h"

#include "SoccerGame/Game/GameFactory.h"

int main(int arc, char* argv[]) {
    StrategySwitcher *lStrategySwitcher = new StrategySwitcher;
    Navigator *lNavigator = new Navigator;
    SoccerGame lSoccerGame(lStrategySwitcher, lNavigator);

    GameFactory lGameFactory;

    lSoccerGame.createSoccerGame(lGameFactory);

    lSoccerGame.startGame();

    return 0;
}

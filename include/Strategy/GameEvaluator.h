#ifndef GAMEEVALUATOR_H
#define GAMEEVALUATOR_H

#include "SoccerGame/Game/Game.h"
#include "SoccerGame/Player/Player.h"
#include "SoccerGame/Team/Team.h"

class GameEvaluator{
public:
    GameEvaluator(Game* iGame);

    static double getDistanceBetweenPlayers(PlayerId iPlayer1, TeamId iTeam1, PlayerId iPlayer2, TeamId iTeam2);
    static double getDistanceBetweenPlayerAndCoord(PlayerId iPlayer, TeamId iTeam, Vector2d coord);
    static PlayerId getClosestPlayer(std::vector<PlayerId> &iPlayers, TeamId iTeam, Vector2d iCoord);
    static bool gameSwitchToHalt();
    static bool gameSwitchToSomething();

private:
    static Game* mGame;

};

#endif // GAMEEVALUATOR_H

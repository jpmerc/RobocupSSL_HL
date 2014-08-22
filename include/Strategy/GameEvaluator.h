#ifndef GAMEEVALUATOR_H
#define GAMEEVALUATOR_H

#include "SoccerGame/Game/Game.h"
#include "Utils/Line.h"

class GameEvaluator{
public:
    GameEvaluator(Game* iGame);

    // Geometric estimation :
    static double getDistanceBetweenPlayers(PlayerId iPlayer1, TeamId iTeam1, PlayerId iPlayer2, TeamId iTeam2);
    static double getDistanceBetweenPlayerAndCoord(PlayerId iPlayer, TeamId iTeam, Vector2d coord);
    static Line getLineBetweenBallAndCoord(Vector2d coord);
    static PlayerId getClosestPlayer(std::vector<PlayerId> &iPlayers, TeamId iTeam, Vector2d iCoord);
    static Pose getBallPose();
    static double getAngleBetweenPlayerAndBall(PlayerId iPlayer, TeamId iTeam);

    //Game state Estimation
    static bool playerAsBall(PlayerId iPlayer, TeamId iTeam,double iAngleTresh = 0.1, double iDistanceTresh = 20);
    static int getCurrentRefCommand();
    static bool refSwitchCommand();

private:
    static Game* mGame;

};

inline Pose GameEvaluator::getBallPose(){
    return mGame->getBall()->getPose();
}

#endif // GAMEEVALUATOR_H

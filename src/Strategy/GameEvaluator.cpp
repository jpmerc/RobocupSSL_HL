#include "Strategy/GameEvaluator.h"

Game *GameEvaluator::mGame = NULL;

GameEvaluator::GameEvaluator(Game * iGame){
    mGame = iGame;
}

double GameEvaluator::getDistanceBetweenPlayers(PlayerId iPlayer1, TeamId iTeam1, PlayerId iPlayer2, TeamId iTeam2){
    Pose player1Position = mGame->getTeams()[iTeam1]->getPlayers()[iPlayer1]->getPose();
    Pose player2Position = mGame->getTeams()[iTeam2]->getPlayers()[iPlayer2]->getPose();
    return player1Position.Position.distanceFromCoordinate(player2Position.Position);

}

double GameEvaluator::getDistanceBetweenPlayerAndCoord(PlayerId iPlayer, TeamId iTeam, Vector2d coord){
    Pose playerPosition = mGame->getTeams()[iTeam]->getPlayers()[iPlayer]->getPose();
    return playerPosition.Position.distanceFromCoordinate(coord);
}

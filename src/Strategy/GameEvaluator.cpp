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

PlayerId GameEvaluator::getClosestPlayerWithoutRole(TeamId iTeam, Vector2d iCoord){
    std::map<PlayerId, Player*> lPlayers = mGame->getTeams()[iTeam]->getPlayers();
    double lFinalDistance = INFINITY;
    PlayerId lPlayerToReturn = 0;
    for (auto it=lPlayers.begin(); it!=lPlayers.end(); ++it){
        if(!it->second->haveRole()){
            PlayerId lPlayer = it->second->getId().getValue();
            double lDistance = GameEvaluator::getDistanceBetweenPlayerAndCoord(lPlayer,iTeam,iCoord);
            if(lDistance < lFinalDistance){
                lFinalDistance = lDistance;
                lPlayerToReturn = lPlayer;
            }
        }
    }
    return lPlayerToReturn;
}

double GameEvaluator::getDistanceBetweenPlayerAndCoord(PlayerId iPlayer, TeamId iTeam, Vector2d iCoord){
    Pose playerPosition = mGame->getTeams()[iTeam]->getPlayers()[iPlayer]->getPose();
    return playerPosition.Position.distanceFromCoordinate(iCoord);
}

bool GameEvaluator::isGamePaused(){
    if(mGame->getRef()->getCommand() == SSL_Referee::HALT){
        return true;
    }
    else{
        return false;
    }
}

#include "Strategy/GameEvaluator.h"

Game *GameEvaluator::mGame = NULL;

GameEvaluator::GameEvaluator(Game * iGame){
    mGame=iGame;
}

double GameEvaluator::getDistanceBetweenPlayers(PlayerId iPlayer1, TeamId iTeam1, PlayerId iPlayer2, TeamId iTeam2){
    Pose player1Position = mGame->getTeams()[iTeam1]->getPlayers()[iPlayer1]->getPose();
    Pose player2Position = mGame->getTeams()[iTeam2]->getPlayers()[iPlayer2]->getPose();
    return player1Position.Position.distanceFromCoordinate(player2Position.Position);

}

PlayerId GameEvaluator::getClosestPlayer(std::vector<PlayerId>& iPlayers, TeamId iTeam, Vector2d iCoord){
    double higherDistance = INFINITY;
    PlayerId lReturnPlayer = 0;
    int lPosition = -1;
    int lReturnPosition = 0;
    for (auto it=iPlayers.begin(); it!=iPlayers.end(); ++it){
        double lDistance = GameEvaluator::getDistanceBetweenPlayerAndCoord((*it),iTeam,iCoord);
        lPosition++;
        if(lDistance < higherDistance){
            higherDistance = lDistance;
            lReturnPlayer = (*it);
            lReturnPosition = lPosition;
        }
    }
    iPlayers.erase(iPlayers.begin()+lReturnPosition);

    return lReturnPlayer;
}

double GameEvaluator::getDistanceBetweenPlayerAndCoord(PlayerId iPlayer, TeamId iTeam, Vector2d iCoord){
    Pose playerPosition = mGame->getTeams()[iTeam]->getPlayers()[iPlayer]->getPose();
    return playerPosition.Position.distanceFromCoordinate(iCoord);
}

bool GameEvaluator::gameSwitchToHalt(){
    if(mGame->getRef()->commandAsChanged()){
        if(mGame->getRef()->getCommand() == SSL_Referee::HALT){
            mGame->getRef()->setCommandChanged(false);
            return true;
        }
    }
    else{
        return false;
    }
}

bool GameEvaluator::gameSwitchToSomething(){
    if(mGame->getRef()->commandAsChanged()){
        if(mGame->getRef()->getCommand() != SSL_Referee::HALT){
            mGame->getRef()->setCommandChanged(false);
            return true;
        }
    }
    else{
        return false;
    }
}

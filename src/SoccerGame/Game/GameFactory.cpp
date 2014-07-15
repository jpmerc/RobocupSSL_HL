#include "SoccerGame/Game/GameFactory.h"

Game* GameFactory::createGame(Ball* iBall, Field* iField) const{
    return new Game(iBall, iField);
}

Field* GameFactory::createField(double iWidth,
    double iHeight,
    double iPlayableWidth,
    double iPlayableHeight
) const{
    return new Field(iWidth, iHeight, iPlayableWidth, iPlayableHeight);
}

Team* GameFactory::createTeam(TeamId iTeamId) const{
    return new Team(iTeamId);
}

Player* GameFactory::createPlayer(PlayerId iPlayerId, TeamId iTeamId,
                                  Navigator *iNavigator) const{
    return new Player(iPlayerId, iTeamId,iNavigator);
}

Ball* GameFactory::createBall(BallId iBallId) const{
    return new Ball(iBallId);
}

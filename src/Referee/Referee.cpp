#include "SoccerGame/Referee/Referee.h"

Referee::Referee()
{
}

void Referee::addListener(RefereeListener *listener)
{
    this->listeners.push_back(listener);
}

void Referee::fireGameStarted()
{
    for(auto listener : this->listeners){
        listener->gameStarted();
    }
}

void Referee::fireGamePaused()
{
    for(auto *listener : this->listeners){
        listener->gamePaused();
    }
}

void Referee::fireGameEnded()
{
    for(auto *listener : this->listeners){
        listener->gameEnded();
    }
}

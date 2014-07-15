#include "Strategy/StrategySwitcher.h"

#include <stdexcept>

StrategySwitcher::StrategySwitcher()
    : isGameEnded(false)
{
    //Choose a default play when game is initialized (NOT yet started)
    this->currentPlay = NULL;
}

StrategySwitcher::~StrategySwitcher()
{
    if(this->currentPlay) delete this->currentPlay;
}

bool StrategySwitcher::isDone()
{
    return this->isGameEnded;
}

void StrategySwitcher::update()
{
    this->findNextPlay();
    this->currentPlay->update();
}

void StrategySwitcher::findNextPlay()
{
    if(this->currentPlay->isDone()){
        Play *newPlay = 0;

        newPlay = this->playFinder.findPlay(*this->currentPlay, this->availablePlays);
        this->switchPlays(newPlay);
    }
}

void StrategySwitcher::switchPlays(Play *newPlay)
{
    delete this->currentPlay;
    this->currentPlay = newPlay;
}

void StrategySwitcher::gameStarted()
{
    this->onGameStarted();
}

void StrategySwitcher::gamePaused()
{
    this->onGamePaused();
}

void StrategySwitcher::gameEnded()
{
    this->onGameEnded();
}

void StrategySwitcher::onGameStarted()
{
    //Choose a default play when game starts
}

void StrategySwitcher::onGamePaused()
{
    //Choose a play when game is paused
}

void StrategySwitcher::onGameEnded()
{
    this->isGameEnded = true;
}

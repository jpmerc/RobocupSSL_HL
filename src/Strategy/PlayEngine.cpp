#include "Strategy/PlayEngine.h"

#include <stdexcept>

PlayEngine::PlayEngine()
    : isGameEnded(false){
    INFO << "Create PlayEngine";
    mAvailablePlays.push_back(new Offense());
    mAvailablePlays.push_back(new KickOff());
    mAvailablePlays.push_back(new Idle());
    //Choose a default play when game is initialized (NOT yet started)
    this->mCurrentPlay = mAvailablePlays[1];
}

PlayEngine::~PlayEngine(){
    if(this->mCurrentPlay) delete this->mCurrentPlay;
}

bool PlayEngine::isDone()
{
    return this->isGameEnded;
}

Play *PlayEngine::update()
{
    if(GameEvaluator::gameSwitchToHalt()){
        this->onGamePaused();
    }
    if(GameEvaluator::gameSwitchToSomething()){
        this->onGameStarted();
    }
    return mCurrentPlay;
}


void PlayEngine::findNextPlay()
{
    if(this->mCurrentPlay->isDone()){
        Play *newPlay = 0;

        //newPlay = this->mPlayFinder.findPlay(*this->mCurrentPlay, this->mAvailablePlays);
        //this->switchPlays(newPlay);
    }
}

void PlayEngine::switchPlays(Play *newPlay)
{
    delete this->mCurrentPlay;
    this->mCurrentPlay = newPlay;
}

void PlayEngine::gameStarted()
{
    this->onGameStarted();
}

void PlayEngine::gamePaused()
{
    this->onGamePaused();
}

void PlayEngine::gameEnded()
{
    this->onGameEnded();
}

void PlayEngine::onGameStarted()
{
    INFO << "Game STARTED";
    this->mCurrentPlay->reset();
    this->mCurrentPlay = mAvailablePlays[1];
}

void PlayEngine::onGamePaused()
{
    INFO << "Game PAUSED";
    this->mCurrentPlay->reset();
    this->mCurrentPlay = mAvailablePlays[2];
}

void PlayEngine::onGameEnded()
{
    this->isGameEnded = true;
}

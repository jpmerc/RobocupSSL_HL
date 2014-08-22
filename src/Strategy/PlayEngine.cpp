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
    this->checkRef();
    return mCurrentPlay;
}

void PlayEngine::checkRef(){

    if(GameEvaluator::refSwitchCommand()){
        switch(GameEvaluator::getCurrentRefCommand()){
        case SSL_Referee::HALT:
            this->onGamePaused();
            break;
        case SSL_Referee::PREPARE_KICKOFF_BLUE:
            mCurrentPlay->forceDone();
            mCurrentPlay = mAvailablePlays[1]; //TODO  call find NextPlay or set special state
            mCurrentPlay->reset();
            break;
        case SSL_Referee::NORMAL_START:
            mCurrentPlay->forceDone();
            mCurrentPlay = mAvailablePlays[0]; //TODO  call find NextPlay or set special state
            mCurrentPlay->reset();
            break;
        default:
            this->onGamePaused();
        }
    }

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
    this->findNextPlay();
}

void PlayEngine::onGamePaused()
{
    INFO << "Game PAUSED";
    this->mCurrentPlay = mAvailablePlays[2];
    this->mCurrentPlay->reset();
}

void PlayEngine::onGameEnded()
{
    this->isGameEnded = true;
}

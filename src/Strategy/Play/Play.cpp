#include "Strategy/Play/Play.h"

#include <stdexcept>
#include <algorithm>

Play::Play()
    : requestedPlay(0)
{
}

Play* Play::getRequestedPlay() const
{
    if(!this->requestedPlay) throw std::runtime_error("No requested play");

    return this->requestedPlay;
}

void Play::update()
{
    this->findNextTactics();
    this->updateTactics();
}

void Play::findNextTactics()
{
    for(auto currentTactic : this->currentTactics){
        if(currentTactic->isDone()){
            Tactic *newTactic = this->tacticFinder.findTactics(currentTactic, this->availableTactics);
            this->switchTactics(currentTactic, newTactic);
        }
    }
}

void Play::updateTactics()
{
    for(auto tactic : this->currentTactics){
        tactic->update();
    }
}

void Play::switchTactics(Tactic *oldTactic, Tactic *newTactic)
{
    if(oldTactic != newTactic){
        auto it = std::find(this->currentTactics.begin(), this->currentTactics.end(), oldTactic);

        if (it != this->currentTactics.end()){
            this->currentTactics.erase(it);

            delete oldTactic;
            this->currentTactics.push_back(newTactic);
        }
    }
}

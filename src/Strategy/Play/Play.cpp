#include "Strategy/Play/Play.h"

#include <stdexcept>
#include <algorithm>


/*Play* Play::getRequestedPlay() const
{
    if(!this->mRequestedPlay) throw std::runtime_error("No requested play");

    return this->mRequestedPlay;
}

void Play::update()
{
    this->findNextTactics();
    this->updateTactics();
}

void Play::findNextTactics()
{
    for(auto currentTactic : this->mCurrentTactics){
        if(currentTactic->isDone()){
            Tactic *newTactic = this->tacticFinder.findTactics(currentTactic, this->mAvailableTactics);
            this->switchTactics(currentTactic, newTactic);
        }
    }
}

void Play::updateTactics()
{
    for(auto tactic : this->mCurrentTactics){
        tactic->update();
    }
}

void Play::switchTactics(Tactic *oldTactic, Tactic *newTactic)
{
    if(oldTactic != newTactic){
        auto it = std::find(this->mCurrentTactics.begin(), this->mCurrentTactics.end(), oldTactic);

        if (it != this->mCurrentTactics.end()){
            this->mCurrentTactics.erase(it);

            delete oldTactic;
            this->mCurrentTactics.push_back(newTactic);
        }
    }
}*/

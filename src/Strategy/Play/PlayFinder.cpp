#include "Strategy/Play/PlayFinder.h"

#include <stdexcept>

/*PlayFinder::PlayFinder()
{
}

Play *PlayFinder::findPlay(const Play &currentPlay, std::vector<Play*> availablePlays)
{
    Play *newPlay = 0;

    try{
        newPlay = currentPlay.getRequestedPlay();
    }
    catch(std::runtime_error &e) {
        newPlay = this->findBestPlay(availablePlays);
    }

    return newPlay;
}

Play *PlayFinder::findBestPlay(std::vector<Play*> availablePlays)
{
    int bestScore = 0;
    Play* bestPlay = 0;

    for(auto play : availablePlays){
        int score = play->scoreCurrentSituation();

        if(score >= bestScore){
            bestScore = score;
            bestPlay = play;
        }
    }

    return bestPlay;
}
*/

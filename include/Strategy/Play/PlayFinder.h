#ifndef PLAYFINDER_H
#define PLAYFINDER_H

#include "Strategy/Play/Play.h"

class PlayFinder
{
public:
    PlayFinder();

    virtual Play* findPlay(const Play &currentPlay, std::vector<Play *> availablePlays);
private:
    Play* findBestPlay(std::vector<Play*> availablePlays);

    std::vector<Play*> availablePlays;
};

#endif // PLAYFINDER_H

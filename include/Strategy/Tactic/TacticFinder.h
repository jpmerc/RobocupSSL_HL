#ifndef TACTICFINDER_H
#define TACTICFINDER_H

#include <vector>

#include "Tactic.h"
#include "SoccerGame/Player/Player.h"


class TacticFinder
{
public:
    TacticFinder();

    virtual Tactic *findTactics(Tactic* currentTactic, const std::vector<Tactic*> &tactics);
};

#endif // TACTICFINDER_H

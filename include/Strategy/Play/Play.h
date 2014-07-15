#ifndef PLAY_H
#define PLAY_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/ScoreGameSituation.h"

class Play : public ScoreGameSituation
{
public:
    virtual ~Play(){}

    Play* getRequestedPlay() const;

    void update();

    virtual bool isDone() = 0;
    virtual int scoreCurrentSituation() = 0;
protected:
    Play();

    virtual void requestPlay() = 0;
    virtual void findNextTactics();
    virtual void updateTactics();

    void switchTactics(Tactic *oldTactic, Tactic *newTactic);

    TacticFinder tacticFinder;

    Play *requestedPlay;
    std::vector<Tactic*> currentTactics;
    std::vector<Tactic*> availableTactics;
};

#endif // PLAY_H

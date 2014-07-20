#ifndef OFFENSE_H
#define OFFENSE_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Tactic/Position.h"
#include "Strategy/ScoreGameSituation.h"
#include "Strategy/Play/Play.h"

#include "Logger/Logging.h"

class Offense : public Play{
public:
    Offense();
    virtual ~Offense(){}

    virtual bool isDone();
    virtual void update();
    virtual int scoreCurrentSituation();
    virtual int getRoleSize();
    virtual void assignRoleToPlayer(Player *iPlayer);
protected:

    virtual void requestPlay();
    virtual void createRoles();

};

inline int Offense::getRoleSize(){
    return mAvailableRoles.size();
}



#endif

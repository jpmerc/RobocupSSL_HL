#ifndef IDLE_H
#define IDLE_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Tactic/Position.h"
#include "Strategy/ScoreGameSituation.h"
#include "Strategy/Play/Play.h"
#include "Strategy/ParameterStruct.h"

#include "SoccerGame/Exception/RobocupException.h"
#include "Logger/Logging.h"

class Idle : public Play{
public:
    Idle();
    virtual ~Idle(){}

    virtual bool isDone();
    virtual void update();
    virtual void reset();
    virtual int scoreCurrentSituation();
    virtual int getRoleSize();
    virtual void assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers);
protected:

    virtual void requestPlay();
    virtual void createRoles();
    virtual Role* getRole(int iId);


};

inline int Idle::getRoleSize(){
    return mAvailableRoles.size();
}



#endif

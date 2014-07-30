#ifndef KICKOFF_H
#define KICKOFF_H

#include <vector>

#include "Strategy/Tactic/TacticFinder.h"
#include "Strategy/Tactic/Tactic.h"
#include "Strategy/Tactic/Position.h"
#include "Strategy/ScoreGameSituation.h"
#include "Strategy/Play/Play.h"
#include "Strategy/ParameterStruct.h"

#include "SoccerGame/Exception/RobocupException.h"
#include "Logger/Logging.h"

class KickOff : public Play{
public:
    KickOff();
    virtual ~KickOff(){}

    virtual bool isDone();
    virtual void update();
    virtual int scoreCurrentSituation();
    virtual int getRoleSize();
    virtual void assignRoleToPlayers(std::map<PlayerId, Player*> iPlayers);
protected:

    virtual void requestPlay();
    virtual void createRoles();
    virtual Role* getRole(int iId);
private:
    std::vector<Pose> mPositions;

};

inline int KickOff::getRoleSize(){
    return mAvailableRoles.size();
}



#endif

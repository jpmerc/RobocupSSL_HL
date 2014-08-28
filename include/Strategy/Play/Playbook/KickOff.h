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
#include "Strategy/Role.h"

class KickOff : public Play{
public:
    KickOff();
    virtual ~KickOff(){}

    virtual void update(std::vector<PlayerId> iPlayers, TeamId iTeam);

protected:

    virtual void requestPlay();
    virtual void createRoles();
private:
    std::vector<Pose> mPositions;

};




#endif

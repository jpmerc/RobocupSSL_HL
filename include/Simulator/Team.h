#ifndef _TEAM_H_
#define _TEAM_H_


#include "RobotModel.h"

class TeamSim{

public:
    TeamSim(int iTeamId, int iNbPlayer);

    int GetTeamId();
    RobotModel *GetRobot(int iId);
private:
    RobotModel *mPlayers[10]; //TODO dynamic list..
};

#endif

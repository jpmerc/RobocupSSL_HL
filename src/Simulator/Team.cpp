#include "Simulator/Team.h"




TeamSim::TeamSim(int iTeamId,int iNbPlayer){
    for(int i = 0; i < iNbPlayer; i++){
        mPlayers[i] = new RobotModel(i,iTeamId);
    }
}

RobotModel* TeamSim::GetRobot(int iId){
    return mPlayers[iId];
}

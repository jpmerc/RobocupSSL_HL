
#include "Simulator/RobotDataContainer.h"


RobotData::RobotData(int iId,int iTeamId):mId(iId),mPose(Pose::ZERO),mTeamId(iTeamId){
}

RobotData::~RobotData(){

}


/**********************************************************************************
**    BALL DATA
***********************************************************************************/
BallData::BallData():mPosition(0,0){
}

BallData::~BallData(){

}





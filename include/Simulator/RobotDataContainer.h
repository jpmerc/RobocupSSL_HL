/****************************************************************************
 *
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Contains field datas of a simulated robot
 *
 *
 *
 ****************************************************************************/

#ifndef _ROBOTDATA_H_
#define _ROBOTDATA_H_

#include "Utils/Pose.h"



class RobotData{

public:
    RobotData(int identificationNumber,int iTeamId);
    ~RobotData();

    void setPose(Pose iPose);
    Pose getPose() const;
    int getId() const;
    int getTeam() const;

protected:
    Pose mPose;
    int mId;
    int mTeamId;

};

inline void RobotData::setPose(Pose iPose){
    mPose = iPose;
}

inline Pose RobotData::getPose() const{
    return mPose;
}

inline int RobotData::getId() const{
    return mId;
}

inline int RobotData::getTeam() const{
    return mTeamId;
}




class BallData
{

public:
    BallData();
    ~BallData();
    void setPosition(double iX, double iY);
    Vector2d getPosition() const;
private:
    Vector2d mPosition;
};

inline void BallData::setPosition(double iX, double iY){
    mPosition = Vector2d(iX,iY);
}

inline Vector2d BallData::getPosition() const{
    return mPosition;
}


#endif

/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: This module use the player's data and set a speed vector to reach
 *the player's goal.
 *
 *TODO:add orientation consideration
 *
 ****************************************************************************/

#ifndef _NAVIGATOR_H_
#define _NAVIGATOR_H_

#include <queue>
#include <map>
#include <cmath>
#include "math.h"
#include "Utils/Pose.h"
#include "Utils/Vector2d.h"
#ifndef Q_MOC_RUN
#include "boost/random.hpp"
#endif
#include <time.h>
//#include "boost/math/constants/calculate_constants.hpp"



class Navigator
{

public:
    Navigator(double iWaypointRadius = 100,double iWaypointAngle = 0.1);
    ~Navigator();

    bool isPositionGoalReached();
    bool isAngleGoalReached();
    Vector2d calculateNewVector();
    Orientation calculateNewOrientation();

    void setActualPose(Pose iPose);
    void setGoalPose(Pose iPose);
    Pose getActualPose();
    Pose getGoalPose();
    bool getIsNewGoalReady();


private:

    double _angleBtwTwoAngles(double iangle1, double iangle2);
    double _calculateSpeed(double iGoalTargetSpeed, double iCurrentSpeed, double distance);
    //Important data to keep for execution
    Pose mActualPose;
    Pose mGoalPose;

    //data to output at the end
    bool mIsNewGoalReady;

    double mWaypointRadius;
    double mWaypointAngle;

};


inline Pose Navigator::getActualPose(){
    return mActualPose;
}

inline Pose Navigator::getGoalPose(){
    return mGoalPose;
}

inline bool Navigator::getIsNewGoalReady(){
    return mIsNewGoalReady;
}

inline void Navigator::setActualPose(Pose iPose){
    mActualPose = iPose;
}

inline void Navigator::setGoalPose(Pose iPose){
    mGoalPose = iPose;
}


#endif

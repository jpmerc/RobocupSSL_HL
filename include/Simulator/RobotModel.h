/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: A robot model, containing robot's field datas, and robot's control bias.
 *
 *
 *TODO: make the model more realistic
 *
 ****************************************************************************/

#ifndef _ROBOTMODEL_H_
#define _ROBOTMODEL_H_

#include "RobotDataContainer.h"
#include "Utils/ProtoBuffWrapper.h"
#include "Utils/Pose.h"

#include <math.h>

#ifndef Q_MOC_RUN
#include "boost/random.hpp"
#endif

#include <QDialog>
#include <QHostAddress>
#include <QtGui>
#include <QtNetwork>
#include <cstring>
#include <cmath>
#include <QTextStream>
#include "Utils/GaussianModel.h"

class QUdpSocket;


#define YELLOW 1
#define BLUE 0
#define PI 3.141592654


class RobotModel: public RobotData{

public:
    RobotModel(int iId, int iTeamId);

    void UpdateSimulationData();
    void receiveCommand(Pose iCommand);

    void setGaussX(GaussianModel iGauss);
    void setGaussY(GaussianModel iGauss);
    void setGaussTheta(GaussianModel iGauss);

    Pose getCommand() const;
    GaussianModel getGaussX() const;
    GaussianModel getGaussY() const;
    GaussianModel getGaussTheta() const;


private:
    //commands to send
    Pose mCommand;
    double mCommandKickSpeed;
    bool  mCommandSpinner;

    Pose mPendingCommand;

    boost::mt19937 *mGenerator;
    boost::normal_distribution<> *mNormalDistribution;
    boost::variate_generator<boost::mt19937&,boost::normal_distribution<> > *mRng;
    GaussianModel mGaussVX,mGaussVY,mGaussVTheta;
    long mSeed;


};

inline Pose RobotModel::getCommand() const{
    return mCommand;
}

inline void RobotModel::setGaussX(GaussianModel iGauss){
    mGaussVX = iGauss;
}

inline void RobotModel::setGaussY(GaussianModel iGauss){
    mGaussVY = iGauss;
}

inline void RobotModel::setGaussTheta(GaussianModel iGauss){
    mGaussVTheta = iGauss;
}

inline GaussianModel RobotModel::getGaussX() const{
    return mGaussVX;
}

inline GaussianModel RobotModel::getGaussY() const{
    return mGaussVY;
}

inline GaussianModel RobotModel::getGaussTheta() const{
    return mGaussVTheta;
}


#endif

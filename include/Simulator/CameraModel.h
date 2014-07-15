/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Simulate a camera and vision system, add gaussian noise, time delay
 *and pack the datas in google protobuf
 *
 *
 *TODO: Make the modele more sophisticated.
 *
 ****************************************************************************/

#ifndef _CAMERAMODEL_H_
#define _CAMERAMODEL_H_

#include "Team.h"
#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"
#include "proto/pb/messages_robocup_ssl_detection.pb.h"
#include "proto/pb/messages_robocup_ssl_geometry.pb.h"
#include "proto/pb/grSim_Packet.pb.h"
#include "proto/pb/grSim_Commands.pb.h"
#include "proto/pb/grSim_Replacement.pb.h"
#include "Utils/ProtoBuffWrapper.h"
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

class CameraModel: public QTimer{
Q_OBJECT
public:
    CameraModel(double iFps = 50);
    ~CameraModel();

    void insertBallWithNoise(SSL_WrapperPacket *iPacket, BallData *iBall);
    void insertRobotWithNoise(SSL_WrapperPacket *iPacket,RobotModel *iRobotData);

    Pose addNoise(Pose iPose);

    void setGaussX(GaussianModel iGauss);
    void setGaussY(GaussianModel iGauss);
    void setGaussTheta(GaussianModel iGauss);

    void setFps(double iFps);
    void setVanishingProbability(double iProb);

    GaussianModel getGaussX() const;
    GaussianModel getGaussY() const;
    GaussianModel getGaussTheta() const;
    double getFps() const;
    double getVanishingProbability() const;

private:
    boost::mt19937 *mGenerator;
    boost::normal_distribution<> *mNormalDistribution;
    boost::uniform_01<> *mUniformDistribution;
    boost::variate_generator<boost::mt19937&,boost::normal_distribution<> > *mRng;
    boost::variate_generator<boost::mt19937&,boost::uniform_01<> > *mRngU;
    GaussianModel mGaussX,mGaussY,mGaussTheta;

    long mSeed,mSeedU;
    double mFps;
    double mVanishingProbability;

};

inline void CameraModel::setGaussX(GaussianModel iGauss){
    mGaussX = iGauss;
}

inline void CameraModel::setGaussY(GaussianModel iGauss){
    mGaussY = iGauss;
}

inline void CameraModel::setGaussTheta(GaussianModel iGauss){
    mGaussTheta = iGauss;
}

inline void CameraModel::setFps(double iFps){
    mFps = iFps;
}

inline void CameraModel::setVanishingProbability(double iProb){
    mVanishingProbability = iProb;
}

inline GaussianModel CameraModel::getGaussX() const{
    return mGaussX;
}

inline GaussianModel CameraModel::getGaussY() const{
    return mGaussY;
}

inline GaussianModel CameraModel::getGaussTheta() const{
    return mGaussTheta;
}

inline double CameraModel::getFps() const{
    return mFps;
}

inline double CameraModel::getVanishingProbability() const{
    return mVanishingProbability;
}


#endif


#include "Simulator/CameraModel.h"

/*********************************************************************************
 *      CAMERA MODEL
 *********************************************************************************/

CameraModel::CameraModel(double iFps):mSeed(0),mSeedU(0),
    mVanishingProbability(0),mFps(iFps),mGaussX(GaussianModel::ZERO),
    mGaussY(GaussianModel::ZERO), mGaussTheta(GaussianModel::ZERO){

    mGenerator = new boost::mt19937(1);
    mNormalDistribution= new boost::normal_distribution<>(0,1);
    mUniformDistribution = new boost::uniform_01<>;
    mRng = new boost::variate_generator<boost::mt19937&,boost::normal_distribution<> >(*mGenerator,*mNormalDistribution);
    mRngU = new boost::variate_generator<boost::mt19937&,boost::uniform_01<> >(*mGenerator,*mUniformDistribution);

    /*************************TIMER***********************************/

    this->setInterval(mFps);  //Camera send Signal timeout() at this interval
    this->stop();

}

CameraModel::~CameraModel(){

}


void CameraModel::insertRobotWithNoise(SSL_WrapperPacket *iPacket,
                                       RobotModel* iRobotData){
    SSL_DetectionRobot* lRobotPacket;
    if(iRobotData->getTeam() == BLUE){
        lRobotPacket = iPacket->mutable_detection()->add_robots_blue();
    }
    else{
        lRobotPacket = iPacket->mutable_detection()->add_robots_yellow();
    }

    Pose lRobotPose = iRobotData->getPose();
    lRobotPose = this->addNoise(lRobotPose);

    addRobotToVisionPacket(lRobotPacket, iRobotData->getId(), lRobotPose);
}

void CameraModel::insertBallWithNoise(SSL_WrapperPacket *iPacket,
                                      BallData *iBall){
    Pose lBallPose = Pose(iBall->getPosition().x,iBall->getPosition().y,0);

    lBallPose = this->addNoise(lBallPose);
    addBallToVisionPacket(iPacket,lBallPose);
}


Pose CameraModel::addNoise(Pose iPose){

    ++mSeed;
    mSeedU += mSeed;
    mRng->engine().seed(mSeed + time(NULL));
    mRng->distribution().reset();
    //mRngU->engine().seed(mSeedU + time(NULL));
    //mRngU->distribution().reset();
    //double lVanish = mRngU->operator ()();
    double lX = iPose.Position.x + (mGaussX.Mean + mRng->operator ()()*mGaussX.Variance);
    double lY = iPose.Position.y + (mGaussY.Mean + mRng->operator ()()*mGaussY.Variance);
    double lTheta = iPose.Angle.getPolar() + (mGaussTheta.Mean +
                                              mRng->operator ()()*mGaussTheta.Variance);

    return Pose(lX,lY,lTheta);
}




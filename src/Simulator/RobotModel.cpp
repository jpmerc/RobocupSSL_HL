
#include "Simulator/RobotModel.h"



RobotModel::RobotModel(int iId, int iTeamId):RobotData(iId,iTeamId),mCommand(Pose::ZERO),
    mCommandKickSpeed(0), mCommandSpinner(false),mSeed(0),mGaussVX(GaussianModel::ZERO),
    mGaussVY(GaussianModel::ZERO),mGaussVTheta(GaussianModel::ZERO)
{
    mGenerator = new boost::mt19937(1);
    mNormalDistribution= new boost::normal_distribution<>(0,1);
    mRng = new boost::variate_generator<boost::mt19937&,boost::normal_distribution<> >(*mGenerator,*mNormalDistribution);
}
void RobotModel::UpdateSimulationData(){

        double lErrorX,lErrorY,lErrorTheta = 0;

        double lRedirectedX = 0;
        double lRedirectedY = 0;
        double lAngle = 0;

        lAngle = mPose.Angle.getPolar();  // x and y are inversed for rotational matrix
        //lRedirectedY = mPendingCommand.Position.y;
        //lRedirectedX = mPendingCommand.Position.x;
        lRedirectedY = mPendingCommand.Position.y*cos(lAngle) - mPendingCommand.Position.x*sin(lAngle);
        lRedirectedX = mPendingCommand.Position.y*sin(lAngle) + mPendingCommand.Position.x*cos(lAngle);

        ++mSeed;
        mRng->engine().seed(mSeed + time(NULL));
        mRng->distribution().reset();

        if(lRedirectedX != 0 || lRedirectedY != 0){ //Gaussian distribution error application
            lErrorX = mGaussVX.Mean + mRng->operator ()()*mGaussVX.Variance;
            lErrorY = mGaussVY.Mean + mRng->operator ()()*mGaussVY.Variance;
            lErrorTheta = mGaussVTheta.Mean + mRng->operator ()()*mGaussVTheta.Variance;
        }
        //TODO find the bug with the gaussian distribution!

        double lCommandx = lRedirectedX;// + lErrorX;
        double lCommandy = lRedirectedY;// + lErrorY;
        double lCommandAngle = mPendingCommand.Angle.getPolar();// + lErrorTheta;
        mCommand = Pose(lCommandx,lCommandy,lCommandAngle);
}

void RobotModel::receiveCommand(Pose iCommand){
    mPendingCommand = iCommand;
}


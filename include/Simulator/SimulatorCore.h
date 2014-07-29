/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: This class control de simulation part of the application. It communicate
 *with google protobuf and UDP
 *The two important parts are:
 *-camera model, it simulate de error and timing of a camera. It as one udp Input
 *from a simulator, and one output to an application
 *
 *-robots model, it contain datas for a team of robot and simulate the bias on them.
 *There is one input from an application and one output to the simulator
 *
 *
 *TODO: Insert this module directly in grSim
 *      Add an other camera for data aquisition
 *
 ****************************************************************************/

#ifndef _SIMULATORCORE_H_
#define _SIMULATORCORE_H_

#include "Utils/Vector2f.h"
#include "InOut/InputStream.h"
#include "InOut/UDPOutputStream.h"
#include "RobotDataContainer.h"
#include "RobotModel.h"
#include "Team.h"
#include "CameraModel.h"

#include <QtGui>
#include <QDialog>

#define TIMER_INTERVAL      50  //Frame per second of cam model (initialisation)


class SimulatorCore: public QObject{

Q_OBJECT

public:
    SimulatorCore(int iNbPlayer);

    bool setCameraUDPConfiguration(QString iHostIn,int iPortIn,
                                   QString iHostOut,int iPortOut);
    void ActivateCamera(bool iIsActivated);

    bool setCommandUDPConfiguration(QString iHostIn,int iPortIn,
                                   QString iHostOut,int iPortOut);
    void sendCommandToGrSim();

    void setRobotsConfig(GaussianModel iGaussX, GaussianModel iGaussY, //TODO make it independent
                         GaussianModel iGaussTheta);
    GaussianModel getRobotGaussX() const;
    GaussianModel getRobotGaussY() const;
    GaussianModel getRobotGaussTheta() const;

    CameraModel* getCamera() const;

private slots:
    void UnWrapVisionPacket(SSL_WrapperPacket);
    void UnWrapCommandPacket(grSim_Packet);
    void SendCameraFrame();

private:

    VisionInputStream *mCameraInput;
    UDPOutputStream *mCameraOutput;
    VisionInputStream *mCommandInput;
    UDPOutputStream *mCommandOutput;

    TeamSim *mYellowTeam;
    TeamSim *mBlueTeam;
    BallData *mBall;

    int mNbPlayerPerTeam;

    CameraModel *mCameraModel;

};

inline CameraModel* SimulatorCore::getCamera() const{
    return mCameraModel;
}

inline GaussianModel SimulatorCore::getRobotGaussX() const{
    return mBlueTeam->GetRobot(0)->getGaussX();
}

inline GaussianModel SimulatorCore::getRobotGaussY() const{
    return mBlueTeam->GetRobot(0)->getGaussY();
}

inline GaussianModel SimulatorCore::getRobotGaussTheta() const{
    return mBlueTeam->GetRobot(0)->getGaussTheta();
}





#endif //_SIMULATORCORE_H_

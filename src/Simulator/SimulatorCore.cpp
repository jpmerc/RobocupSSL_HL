
#include "Simulator/SimulatorCore.h"

SimulatorCore::SimulatorCore(int iNbPlayer):mNbPlayerPerTeam(iNbPlayer){

    /*************************GAME***********************************/
    mYellowTeam = new TeamSim(YELLOW,mNbPlayerPerTeam);
    mBlueTeam = new TeamSim(BLUE,mNbPlayerPerTeam);
    mBall = new BallData();
    mCameraModel = new CameraModel(TIMER_INTERVAL);
    connect(mCameraModel, SIGNAL(timeout()), this, SLOT(SendCameraFrame()));

    /*************************IN/OUT***********************************/
    boost::asio::io_service IOService;
    mCameraInput = new VisionInputStream(IOService,"127.0.0.1",20003);
    mCameraOutput = new UDPOutputStream(IOService,"127.0.0.1",20009);
    mCommandInput = new VisionInputStream(IOService,"127.0.0.1",20004);
    mCommandOutput = new UDPOutputStream(IOService,"127.0.0.1",20011);

    mCameraModel->start();

}

void SimulatorCore::sendCommandToGrSim(){
    for(int i = 0; i < mNbPlayerPerTeam; ++i){
        RobotModel* lRobotBlue = mBlueTeam->GetRobot(i);
        //mCommandOutput->AddgrSimCommand(lRobotBlue->getCommand(),
                                       // BLUE,
                                       // lRobotBlue->getId());
    }
    mCommandOutput->SendCommandDatagram();
}


//Slot Unwrapper for internet datagram (vision)
void SimulatorCore::UnWrapVisionPacket(SSL_WrapperPacket iPacketTeam){
    SSL_DetectionRobot lPacketRobotBlue;
    SSL_DetectionRobot lPacketRobotYellow;
    SSL_DetectionBall lPacketBall = iPacketTeam.detection().balls(0);
    int lBlueSize = iPacketTeam.detection().robots_blue_size();
    int lYellowSize = iPacketTeam.detection().robots_blue_size();
    mBall->setPosition(lPacketBall.x(),lPacketBall.y());

    for(int i = 0; i < lBlueSize; ++i){
        lPacketRobotBlue = iPacketTeam.detection().robots_blue(i);
        int RobotId = lPacketRobotBlue.robot_id();
        if(RobotId > mNbPlayerPerTeam - 1){
            break;  //TODO clean this with dynamic player allocation
        }
        RobotModel* lRobotBlue = mBlueTeam->GetRobot(RobotId);
        lRobotBlue->setPose(Pose(lPacketRobotBlue.x(),lPacketRobotBlue.y(),
                                 lPacketRobotBlue.orientation()));
        // TODO should be in another function
        lRobotBlue->UpdateSimulationData();
    }

    for(int i = 0; i < lYellowSize; ++i){
        lPacketRobotYellow = iPacketTeam.detection().robots_yellow(i);
        int RobotId = lPacketRobotYellow.robot_id();
        if(RobotId > mNbPlayerPerTeam - 1){
            break;  //TODO clean this with dynamic player allocation
        }
        RobotModel* lRobotYellow = mYellowTeam->GetRobot(RobotId);
        lRobotYellow->setPose(Pose(lPacketRobotYellow.x(),lPacketRobotYellow.y(),
                                 lPacketRobotYellow.orientation()));
    }

    this->sendCommandToGrSim(); //TODO not clear, send back the new command to grsim
}

void SimulatorCore::UnWrapCommandPacket(grSim_Packet iPacket){
    int size = iPacket.commands().robot_commands().size();
    Pose lCommand;
    for(int i = 0; i < size; ++i){
        int lID = iPacket.commands().robot_commands().Get(i).id();
        RobotModel* lRobot = mBlueTeam->GetRobot(lID);
        lCommand = unWrapCommand(&iPacket, lID);
        lRobot->receiveCommand(lCommand);
    }
}

//Slot Send noised camera output to the internet (vision)
void SimulatorCore::SendCameraFrame(){
    SSL_WrapperPacket lPacket;
    lPacket.mutable_detection()->set_camera_id(0);
    lPacket.mutable_detection()->set_frame_number(0);
    lPacket.mutable_detection()->set_t_capture(0);
    lPacket.mutable_detection()->set_t_sent(0);

    for(int i = 0; i < mNbPlayerPerTeam; ++i){
        mCameraModel->insertRobotWithNoise(&lPacket, mYellowTeam->GetRobot(i));
        mCameraModel->insertRobotWithNoise(&lPacket, mBlueTeam->GetRobot(i));
    }
    mCameraModel->insertBallWithNoise(&lPacket,mBall);

    mCameraOutput->SendUDPVisionDatagram(lPacket);
}




void SimulatorCore::ActivateCamera(bool iIsActivated){
    if(iIsActivated){
        mCameraModel->start();
    }
    else{
        mCameraModel->stop();
    }
}

void SimulatorCore::setRobotsConfig(GaussianModel iGaussX, GaussianModel iGaussY,
                     GaussianModel iGaussTheta){
    for(int i = 0; i < mNbPlayerPerTeam; ++i){
        RobotModel *lBlue = mBlueTeam->GetRobot(i);
        lBlue->setGaussX(iGaussX);
        lBlue->setGaussY(iGaussY);
        lBlue->setGaussTheta(iGaussTheta);

        RobotModel *lYellow = mYellowTeam->GetRobot(i);
        lYellow->setGaussX(iGaussX);
        lYellow->setGaussY(iGaussY);
        lYellow->setGaussTheta(iGaussTheta);
    }
}




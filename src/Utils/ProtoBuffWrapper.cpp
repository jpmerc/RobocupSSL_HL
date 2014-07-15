
#include "Utils/ProtoBuffWrapper.h"

void addCommandToGrSimPacket(grSim_Packet * iPacket, int iId, Pose iPose,
                             bool iIsTeamYellow){

    iPacket->mutable_commands()->set_isteamyellow(iIsTeamYellow);
    iPacket->mutable_commands()->set_timestamp(0.0);
    grSim_Robot_Command* lCommand = iPacket->mutable_commands()->add_robot_commands();

    lCommand->set_id(iId);
    lCommand->set_wheelsspeed(false); //because we use the robot vel command
    lCommand->set_wheel1(0);
    lCommand->set_wheel2(0);
    lCommand->set_wheel3(0);
    lCommand->set_wheel4(0);
    lCommand->set_veltangent(iPose.Position.x);
    lCommand->set_velnormal(iPose.Position.y);
    lCommand->set_velangular(iPose.Angle.getPolar());

    lCommand->set_kickspeedx(0);
    lCommand->set_kickspeedz(0);
    lCommand->set_spinner(0);

}

Pose unWrapCommand(grSim_Packet * iPacket, int iId){
    double lX = iPacket->commands().robot_commands().Get(iId).veltangent();
    double lY = iPacket->commands().robot_commands().Get(iId).velnormal();
    double lAngle = iPacket->commands().robot_commands().Get(iId).velangular();

    return Pose(lX,lY,lAngle);
}

void addRobotToVisionPacket(SSL_DetectionRobot* iRobotPacket, int iId, Pose iPose){
    iRobotPacket->set_confidence(1);
    iRobotPacket->set_pixel_x(0);
    iRobotPacket->set_pixel_y(0);
    iRobotPacket->set_robot_id(iId);
    iRobotPacket->set_x(iPose.Position.x);
    iRobotPacket->set_y(iPose.Position.y);
    iRobotPacket->set_orientation(iPose.Angle.getPolar());
}

void addBallToVisionPacket(SSL_WrapperPacket *iPacket, Pose iPose){
    SSL_DetectionBall* lBall = iPacket->mutable_detection()->add_balls();
    lBall->set_x(iPose.Position.x);
    lBall->set_y(iPose.Position.y);
    lBall->set_confidence(1);
    lBall->set_pixel_x(0);
    lBall->set_pixel_y(0);
}

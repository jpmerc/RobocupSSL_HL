/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Level of abstraction to use google protobuff with robocup
 *
 *
 *
 ****************************************************************************/

#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"
#include "proto/pb/messages_robocup_ssl_detection.pb.h"
#include "proto/pb/messages_robocup_ssl_geometry.pb.h"
#include "proto/pb/grSim_Packet.pb.h"
#include "proto/pb/grSim_Commands.pb.h"
#include "proto/pb/grSim_Replacement.pb.h"

#include "Utils/Pose.h"


void addCommandToGrSimPacket(grSim_Packet * iPacket,int iId, Pose iPose,
                             bool iIsTeamYellow);

Pose unWrapCommand(grSim_Packet * iPacket, int iId);

void addRobotToVisionPacket(SSL_DetectionRobot* iRobotPacket, int iId, Pose iPose);

void addBallToVisionPacket(SSL_WrapperPacket *iPacket, Pose iPose);

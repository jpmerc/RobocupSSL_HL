#include <iostream>
#include "InOut/InputStream.h"
#include "InOut/OutputStream.h"
#include "InOut/UDPOutputStream.h"
#include "Logger/Logging.h"

void unwrapPackets(SSL_WrapperPacket* iWrapperPacket);
grSim_Packet createCommandPacket();

int main(int argc, char *argv[])
{
    INFO << "Starting Multivariable Control Tests";

    grSim_Packet lPacket;
    boost::asio::io_service lIOService;
    VisionInputStream *lVisionInputStream;
    UDPOutputStream *lCommandStream;
    std::string lVisionAddress = "224.5.23.2";
    int lVisionPort = 10020;
    std::string lGrSimAddress = "127.0.0.1";
    int lGrSimPort = 20011;

    INFO << "Create conncetions";
    lVisionInputStream = new VisionInputStream(lIOService,lVisionAddress,lVisionPort);
    lCommandStream = new UDPOutputStream(lIOService,lGrSimAddress,lGrSimPort);

    while(1){
        INFO << "Wait for Vision datagram";
        try{
             lIOService.run();
             lIOService.reset();
         }
         catch(std::exception& e){
             ERROR << e.what();
         }

        unwrapPackets(lVisionInputStream->getPacket());

        lCommandStream->SendCommandDatagram(createCommandPacket());

    }

}

void unwrapPackets(SSL_WrapperPacket* iWrapperPacket){

    int lRobotId = 0;
    int lBallId = 0;

    INFO << "--------------Vision Datagram--------------";

    INFO << "Ball:";
    INFO << "X : " << iWrapperPacket->detection().balls(lBallId).x();
    INFO << "Y : " << iWrapperPacket->detection().balls(lBallId).y();

    INFO << "Blue Robot ID : " << lRobotId;
    INFO << "X : " << iWrapperPacket->detection().robots_blue().Get(lRobotId).x() ;
    INFO << "Y : " << iWrapperPacket->detection().robots_blue().Get(lRobotId).y() ;
    INFO << "Theta : " << iWrapperPacket->detection().robots_blue().Get(lRobotId).orientation() ;

    INFO << "-------------------------------------------";

}

grSim_Packet createCommandPacket(){

    grSim_Packet lPacket;

    lPacket.mutable_commands()->set_isteamyellow(false);
    lPacket.mutable_commands()->set_timestamp(0.0);
    grSim_Robot_Command* lCommand = lPacket.mutable_commands()->add_robot_commands();

    lCommand->set_id(0);
    lCommand->set_wheelsspeed(true);
    lCommand->set_wheel1(0);
    lCommand->set_wheel2(10);
    lCommand->set_wheel3(0);
    lCommand->set_wheel4(10);
    lCommand->set_veltangent(0);
    lCommand->set_velnormal(0);
    lCommand->set_velangular(0);
    lCommand->set_kickspeedx(0);
    lCommand->set_kickspeedz(0);
    lCommand->set_spinner(0);

    return lPacket;
}

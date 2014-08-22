#include "InOut/UDPOutputStream.h"

UDPOutputStream::UDPOutputStream(boost::asio::io_service &iIOService, std::string iAddress, int iPort)
    :mEndPoint(boost::asio::ip::address::from_string(iAddress), iPort){
    mGrSimPacket = new grSim_Packet;
    INFO << "Creating socket";
    mSocket.reset(new boost::asio::ip::udp::socket(iIOService));
    mSocket->open(boost::asio::ip::udp::v4());
}

UDPOutputStream::~UDPOutputStream(){
    mSocket.reset(NULL);
    delete mGrSimPacket;
}


void UDPOutputStream::AddgrSimCommand(CommandStruct& iCommand,bool iTeam){

    addCommandToGrSimPacket(mGrSimPacket, iCommand, iTeam);
}

void UDPOutputStream::SendCommandDatagram(){

    int lSize = mGrSimPacket->ByteSize();
    char lSend_buffer[lSize];
    mGrSimPacket->SerializeToArray(lSend_buffer, lSize);
    this->SendData(lSend_buffer,lSize);
    mGrSimPacket->clear_commands();

}

void UDPOutputStream::SendUDPVisionDatagram(SSL_WrapperPacket iPacket){
    int lSize = iPacket.ByteSize();
    char lSend_buffer[lSize];
    mGrSimPacket->SerializeToArray(lSend_buffer, lSize);
    this->SendData(lSend_buffer,lSize);
}



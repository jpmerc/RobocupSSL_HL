/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Module to send command to a UDP port.
 *the user must add commands in the grsim packet, and then the module create an
 *UDP datagram and send it over the ethernet.
 *
 *
 *
 ****************************************************************************/

#ifndef UDPOUTPUTSTREAM_H
#define UDPOUTPUTSTREAM_H

#include "OutputStream.h"

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>

#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"
#include "proto/pb/messages_robocup_ssl_detection.pb.h"
#include "proto/pb/messages_robocup_ssl_geometry.pb.h"
#include "proto/pb/grSim_Packet.pb.h"
#include "proto/pb/grSim_Commands.pb.h"
#include "proto/pb/grSim_Replacement.pb.h"
#include "Utils/ProtoBuffWrapper.h"

#include <cstring>
#include <cmath>
#include <vector>

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>

using boost::asio::ip::udp;

class UDPOutputStream: public OutputStream{
public:
    UDPOutputStream(boost::asio::io_service& iIOService, std::string iAddress, int iPort);
    virtual ~UDPOutputStream();

    virtual void SetConnection(std::string iAdress);
    virtual void SetData(int iPort);
    virtual void AddgrSimCommand(CommandStruct &iCommand, bool iTeam);
    void SendCommandDatagram(grSim_Packet iGrSimPacket);
    virtual void SendCommandDatagram();

    void SendUDPVisionDatagram(SSL_WrapperPacket iPacket);

private:

    void SendData(char* iMsg, int iSize);

    std::string mAddress;
    int mPort;
    grSim_Packet *mGrSimPacket;

    boost::asio::ip::udp::endpoint                  mEndPoint;
    boost::scoped_ptr<boost::asio::ip::udp::socket> mSocket;
    boost::asio::io_service *                         mIOService;


};

inline void UDPOutputStream::SetConnection(std::string iAdress){
    this->mAddress = iAdress;
}

inline void UDPOutputStream::SetData(int iPort){
    mPort = iPort;
}

inline void UDPOutputStream::SendData(char* iMsg, int iSize){
    mSocket->send_to(boost::asio::buffer(iMsg,iSize), mEndPoint);
}



#endif //UDPOUTPUTSTREAM_H

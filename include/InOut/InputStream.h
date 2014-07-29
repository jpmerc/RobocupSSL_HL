/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: This module is an api to create communication with UDP
 *input: udp datagram
 *output: google protobuf
 *
 *The three kind of protobuf are decoupled so we know what is shared.
 *
 *
 ****************************************************************************/

#ifndef INPUT_H
#define INPUT_H

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/bind.hpp>
#include "Logger/Logging.h"

#include "proto/pb/messages_robocup_ssl_wrapper.pb.h"
#include "proto/pb/messages_robocup_ssl_detection.pb.h"
#include "proto/pb/messages_robocup_ssl_geometry.pb.h"
#include "proto/pb/referee.pb.h"
#include "proto/pb/grSim_Packet.pb.h"
#include "proto/pb/grSim_Commands.pb.h"
#include "proto/pb/grSim_Replacement.pb.h"

#include <cstring>
#include <cmath>
#include <QTextStream>
#include <vector>

using boost::asio::ip::udp;


class InputStream{
public:
    InputStream(boost::asio::io_service& io_service, std::string iMulticastAdress, int iPort);
    virtual ~InputStream();

protected:

    void startReceive();
    virtual void handleReceive(const boost::system::error_code& error,
                        std::size_t bytes_transferred) = 0;

    std::string mMessage;

    boost::asio::io_service& mIOService;

    udp::socket mSocket;
    udp::endpoint mRemoteEndpoint;
    boost::array<char, 550> mRecvbuffer;


};


class VisionInputStream:public InputStream{
public:
    VisionInputStream(boost::asio::io_service& io_service, std::string iMulticastAdress, int iPort);
    SSL_WrapperPacket getPacket();

protected:
    virtual void handleReceive(const boost::system::error_code& error,
                        std::size_t bytes_transferred);

private:
    SSL_WrapperPacket mPacket;
};

inline SSL_WrapperPacket VisionInputStream::getPacket(){
    return mPacket;
}


class RefInputStream:public InputStream{
public:
    RefInputStream(boost::asio::io_service& io_service, std::string iMulticastAdress, int iPort);
    SSL_Referee getPacket();

protected:
    virtual void handleReceive(const boost::system::error_code& error,
                        std::size_t bytes_transferred);

private:
    SSL_Referee mPacket;
};

inline SSL_Referee RefInputStream::getPacket(){
    return mPacket;
}


#endif //INPUT_H


#include "InOut/InputStream.h"

InputStream::InputStream(boost::asio::io_service &io_service,std::string iMulticastAdress, int iPort):
    mSocket(io_service, udp::endpoint(udp::v4(), iPort)), mIOService(io_service){
    INFO << "Bind Socket to port " << iPort;
    // Join the multicast group.
    boost::asio::ip::address multicast_address = boost::asio::ip::address::from_string(iMulticastAdress);
    mSocket.set_option(boost::asio::ip::multicast::join_group(multicast_address));
    startReceive();
}

InputStream::~InputStream(){

}


void InputStream::startReceive(){
    mSocket.async_receive_from(
        boost::asio::buffer(mRecvbuffer), mRemoteEndpoint,
        boost::bind(&InputStream::handleReceive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void InputStream::handleReceive(const boost::system::error_code& error,
      std::size_t bytes_transferred){
    if (!error || error == boost::asio::error::message_size){
        mVisionMessage = std::string(mRecvbuffer.begin(), mRecvbuffer.end());
        mVisionPacket.ParseFromString(mVisionMessage);
        startReceive();
        mIOService.stop();
    }
}

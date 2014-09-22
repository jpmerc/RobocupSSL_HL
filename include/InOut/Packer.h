/*
    Robocup Protocol V1.1

    | Robot's Id | Command | Data |
    Velocity command :
    |id|1|Vx|Vy|Vtheta|
    char|char|float|float|float

    -----
    PID command :
    |id|2|P|I|D|
    char|char|float|float|float

*/


#ifndef PACKER_H
#define PACKER_H

#include <queue>
#include <iostream>
#include <boost/asio.hpp>
using namespace::boost::asio;

using namespace std;

typedef union dataConverter {
    float floatValue;
    int intValue;
    unsigned char charValues[4];
}dataConverter;


class Packer{
public:
    Packer(boost::asio::serial_port * pSerial);
    void createSpeedCommand(const float iX,const float iY,const float iTheta,const unsigned char iId);
    void createSetPidCommand(float iP, float iI, float iD, unsigned char iId); //It could be the same function but for now it read better
    static unsigned char STARTBYTE;
    static unsigned char STOPBYTE;
    static unsigned char ESCAPEBYTE;

    void sendPacket();
    void printPacket();

private:
    void pppProtocol();
    void insertFloatInPacket(float iData);
    void insertIntInPacket(int iData);
    void insertStartByteInPacket();
    void insertStopByteInPacket();

    dataConverter mDataConverter;
    boost::asio::serial_port * mSerial;
    queue<unsigned char> mPacket;

};



#endif


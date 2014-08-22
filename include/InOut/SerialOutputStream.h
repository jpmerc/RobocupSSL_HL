/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Module to send command to a serial port.
 *the user must add commands in the grsim packet, and then the module unpack all
 *command and send them to serial device.
 *
 *
 ****************************************************************************/

#ifndef SERIALOUTPUTSTREAM_H
#define SERIALOUTPUTSTREAM_H

#include "boost/asio.hpp"
#include <map>
#include "OutputStream.h"
#include "Packer.h"


using namespace::boost::asio;
using namespace std;

class SerialOutputStream : public OutputStream{
public:
    SerialOutputStream(string iPort,int iBd);
    virtual ~SerialOutputStream();
    virtual void SetConnection(std::string idata);
    virtual void SetData(int idata);
    virtual void AddgrSimCommand(CommandStruct &iCommand, bool iTeam);
    virtual void SendCommandDatagram();

    void updateSetting(string iPort, unsigned int iBaudrate);
    void updateParameter(int iBd,
                         int iCarSize,
                         boost::asio::serial_port_base::flow_control iFlow,
                         boost::asio::serial_port_base::parity iParity,
                         boost::asio::serial_port_base::stop_bits iStopBit);
    void write(float iS,float iM);

private:
    boost::asio::io_service mIO;
    boost::asio::serial_port mSerial;
    vector<CommandStruct> mCommands;
    Packer *mPacker;


};

inline void SerialOutputStream::write(float iS, float iM){
    float lCommand[2] = {iS, iM};
    boost::asio::write(mSerial, buffer(lCommand,8));
}

#endif // SERIALOUTPUTSTREAM_H

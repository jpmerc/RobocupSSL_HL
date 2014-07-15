/****************************************************************************
 *Author : Mathieu Garon  mathieugaron1991@hotmail.com
 *
 *Purpose: Interface for output stream. in this case the interface permit
 *the use of udp stream or serial stream. It give necessary initialisation
 *setting and interface to contruct and send grsim packet.
 *
 *TODO: find a better way to name or to set connection
 *
 ****************************************************************************/

#ifndef OUTPUTSTREAM_H
#define OUTPUTSTREAM_H

#include <iostream>
#include <sstream>
#include "Utils/Pose.h"
#include "Logger/Logging.h"

class OutputStream{
public:
    virtual ~OutputStream(){}
    virtual void SetConnection(std::string idata) = 0;
    virtual void SetData(int idata) = 0;

    virtual void AddgrSimCommand(Pose iCommand,bool iTeam,int iRobotId) = 0;
    virtual void SendCommandDatagram() = 0;

private:


};

#endif // OUTPUTSTREAM_H

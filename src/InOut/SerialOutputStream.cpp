#include "InOut/SerialOutputStream.h"


SerialOutputStream::SerialOutputStream(string iPort,int iBd): mIO(), mSerial(mIO,iPort){

    // what baud rate do we communicate at
    serial_port_base::baud_rate lBaudRate(iBd);
    // what caracters size is used (default is 8)
    serial_port_base::character_size lCarSize( 8 );
    // what flow control is used (default is none)
    serial_port_base::flow_control lFlowMod( serial_port_base::flow_control::none );
    // what parity is used (default is none)
    serial_port_base::parity lParity( serial_port_base::parity::none );
    // how many stop bits are used (default is one)
    serial_port_base::stop_bits lStopBit( serial_port_base::stop_bits::one );


    mSerial.set_option(lBaudRate);
    mSerial.set_option(lCarSize);
    mSerial.set_option(lFlowMod);
    mSerial.set_option(lParity);
    mSerial.set_option(lStopBit);

    mPacker = new Packer(&mSerial);

}

SerialOutputStream::~SerialOutputStream(){

}

void SerialOutputStream::AddgrSimCommand(CommandStruct& iCommand, bool iTeam){
    mCommands.push_back(iCommand);
}

void SerialOutputStream::SendCommandDatagram(){


   for(auto it = mCommands.begin(); it != mCommands.end();++it){
       mPacker->createSpeedCommand(it->velocity.Position.x,
                                   it->velocity.Position.y,
                                   it->velocity.Angle.getPolar(),
                                   it->playerId.getValue());
       mPacker->sendPacket();
   }

   mCommands.clear();
}

void SerialOutputStream::SetConnection(string idata){

}

void SerialOutputStream::SetData(int idata){

}

void SerialOutputStream::updateParameter(int iBd, int iCarSize,
                                         serial_port_base::flow_control iFlow,
                                         serial_port_base::parity iParity,
                                         serial_port_base::stop_bits iStopBit){
    mSerial.set_option(serial_port_base::baud_rate(iBd));
    mSerial.set_option(serial_port_base::character_size(iCarSize));
    mSerial.set_option(iFlow);
    mSerial.set_option(iParity);
    mSerial.set_option(iStopBit);
}

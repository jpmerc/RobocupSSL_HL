//version 1.0
#include "InOut/Packer.h"

Packer::Packer(boost::asio::serial_port *pSerial){
    mSerial = pSerial;
}

unsigned char Packer::STARTBYTE = 0x7E;
unsigned char Packer::STOPBYTE = 0x7F;
unsigned char Packer::ESCAPEBYTE = 0x7D;

void Packer::createSpeedCommand(const float iX, const float iY, const float iTheta, const unsigned char iId){
    std::queue<unsigned char> emptyQueue;
    std::swap( mPacket, emptyQueue);

    this->insertStartByteInPacket();
    mPacket.push(iId);
    mPacket.push(char(1));
    this->insertFloatInPacket(iX);
    this->insertFloatInPacket(iY);
    this->insertFloatInPacket(iTheta);
    this->insertStopByteInPacket();
}

void Packer::createSetPidCommand(float iP, float iI, float iD, unsigned char iId){
}

void Packer::sendPacket(){
    int lSize = this->mPacket.size();
    char lBuffer[lSize];
    for(int i = 0; i < lSize; ++i){
        lBuffer[i] = mPacket.front();
        mPacket.pop();
    }
    boost::asio::write(*this->mSerial,buffer(lBuffer,lSize));
}


void Packer::insertFloatInPacket(float iData){
    mDataConverter.floatValue = iData;
    for(int i = 0; i < 4; ++i){
        if(mDataConverter.charValues[i] == this->STARTBYTE || mDataConverter.charValues[i] == this->ESCAPEBYTE || mDataConverter.charValues[i] == this->STOPBYTE){
            mPacket.push(this->ESCAPEBYTE);
        }
        mPacket.push(mDataConverter.charValues[i]);
    }
}


void Packer::insertIntInPacket(int iData){
    mDataConverter.intValue = iData;
    for(int i = 0; i < 4; ++i){
        if(mDataConverter.charValues[i] == this->STARTBYTE || mDataConverter.charValues[i] == this->ESCAPEBYTE || mDataConverter.charValues[i] == this->STOPBYTE){
            mPacket.push(this->ESCAPEBYTE);
        }
        mPacket.push(mDataConverter.charValues[i]);
    }
}

void Packer::insertStartByteInPacket(){
    mPacket.push(this->STARTBYTE);
}

void Packer::insertStopByteInPacket(){
    mPacket.push(this->STOPBYTE);
}

void Packer::printPacket(){
    std::queue<unsigned char> lCopy(mPacket);
    int lSize = lCopy.size();
    std::cout << "Printing Packet of length : " << lSize << std::endl;
    std::cout << "---------------------------------------------- " << std::endl;
    for(int i = 0; i < lSize; ++i){
        printf("%x ",lCopy.front());
        lCopy.pop();
    }
    std::cout << std::endl << "---------------------------------------------- " << std::endl;
}

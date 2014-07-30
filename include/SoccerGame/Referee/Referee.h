#ifndef REFEREE_H
#define REFEREE_H

#include <vector>

#include "proto/pb/referee.pb.h"
#include "Logger/Logging.h"


class Referee
{
public:
    Referee();

    void setData(SSL_Referee* iPacket);

    int getCommand();
    int getStage();
    int getTimeLeft();

private:
    int mStage;
    int mStageTimeLeft;
    int mCommand;

};

inline int Referee::getCommand(){
    return mCommand;
}
inline int Referee::getStage(){
    return mStage;
}
inline int Referee::getTimeLeft(){
    return mStageTimeLeft;
}




#endif // REFEREE_H

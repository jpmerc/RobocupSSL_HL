#ifndef REFEREE_H
#define REFEREE_H

#include <vector>

#include "proto/pb/referee.pb.h"


class Referee
{
public:
    Referee();

    void setData(SSL_Referee* iPacket);

private:
    SSL_Referee::Stage mStage;
    int mStageTimeLeft;
    SSL_Referee::Command mCommand;

};


#endif // REFEREE_H

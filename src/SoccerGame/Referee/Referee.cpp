#include "SoccerGame/Referee/Referee.h"

Referee::Referee()
{
}

void Referee::setData(SSL_Referee* iPacket){
    mCommand = iPacket->command();
    mStage = iPacket->stage();
    mStageTimeLeft = iPacket->stage_time_left();
    INFO << "Command : " << mCommand << "Stage : " << mStage << "Time left : " << mStageTimeLeft;
}

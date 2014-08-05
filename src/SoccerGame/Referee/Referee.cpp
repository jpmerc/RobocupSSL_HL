#include "SoccerGame/Referee/Referee.h"

Referee::Referee()
{
}

void Referee::setData(SSL_Referee* iPacket){
    mLastCommand = mCommand;
    mCommand = iPacket->command();
    if(mCommand!=mLastCommand){
        mCommandChanged = true;
    }
    mStage = iPacket->stage();
    mStageTimeLeft = iPacket->stage_time_left();
    INFO << "Command : " << mCommand << "Stage : " << mStage << "Time left : " << mStageTimeLeft;
}

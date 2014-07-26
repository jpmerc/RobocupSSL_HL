#ifndef COMMANDSTRUCT_H
#define COMMANDSTRUCT_H
#include "Utils/Pose.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"

typedef struct CommandStruct{
    PlayerId playerId;
    Pose target;
    bool kickFlag;
    bool dribleFlag;
    double kickSpeed;

    CommandStruct(Pose iTarget = Pose::ZERO):playerId(0),target(iTarget), kickFlag(false),dribleFlag(false),kickSpeed(0){}

}CommandStruct;

#endif

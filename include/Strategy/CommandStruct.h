#ifndef COMMANDSTRUCT_H
#define COMMANDSTRUCT_H
#include "Utils/Pose.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"

typedef struct CommandStruct{
    PlayerId playerId;

    Pose positionTarget;

    Pose velocity;
    bool kickFlag;
    bool dribleFlag;
    double kickSpeed;

    bool stopFlag;

    CommandStruct(Pose iTarget = Pose::ZERO):playerId(0),positionTarget(iTarget),velocity(Pose::ZERO), kickFlag(false),
        dribleFlag(false),kickSpeed(0),stopFlag(false){}

}CommandStruct;

#endif

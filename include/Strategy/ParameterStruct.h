#ifndef PARAMETERSTRUCT_H
#define PARAMETERSTRUCT_H
#include "Utils/Pose.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"

typedef struct ParameterStruct{
    PlayerId playerId;
    TeamId teamId;

    Pose positionTarget;
    TeamId teamTarget;
    PlayerId playerTarget;
    bool isPoseTarget;

    bool isIdle;

    ParameterStruct(Pose iTarget = Pose::ZERO):playerId(0),teamId(0),positionTarget(iTarget),
        teamTarget(0), playerTarget(0),isPoseTarget(true),isIdle(false){}

}ParameterStruct;

#endif

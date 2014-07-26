#ifndef PARAMETERSTRUCT_H
#define PARAMETERSTRUCT_H
#include "Utils/Pose.h"
#include "SoccerGame/Player/PlayerId.h"
#include "SoccerGame/Team/TeamId.h"

typedef struct ParameterStruct{
    PlayerId playerId;
    TeamId teamId;
    Pose target;
    int roleTarget;

    ParameterStruct(Pose iTarget = Pose::ZERO):playerId(0),teamId(0),target(iTarget), roleTarget(0){}

}ParameterStruct;

#endif

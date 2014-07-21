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

    ParameterStruct():playerId(0),teamId(0),target(0,0,0), roleTarget(0){}

}ParameterStruct;

#endif

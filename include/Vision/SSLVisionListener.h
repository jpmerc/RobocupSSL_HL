#ifndef SSLVISIONLISTENER_H
#define SSLVISIONLISTENER_H

#include "Utils/Vector2f.h"
#include "Game/Player/PlayerId.h"

class SSLVisionListener {
public:
    virtual void updateBallCoordinate(const Vector2d &newCoordinate) = 0;
    virtual void updatePlayersCoordinates(const std::map<PlayerId, Vector2d> &newCoordinate) = 0;
};

#endif

#ifndef POSE_H
#define POSE_H

#include "Vector2d.h"
#include "Orientation.h"

class Pose
{
public:
    Pose(Vector2d iPosition, Orientation iOrientation, double iSpeed = 0);
    Pose(Vector2d iPosition, double iOrientation, double iSpeed = 0);
    Pose(double iX, double iY, Orientation iOrientation, double iSpeed = 0);
    Pose(double iX = 0, double iY = 0, double iOrientation = 0, double iSpeed = 0);
    Pose(const Pose &other);

    void setPosition(double x, double y);

    Pose fromGlobalToRelative(const double iAngleRelative);

    bool operator==(const Pose &other) const;
    bool operator!=(const Pose &other) const;

    Vector2d Position;
    Orientation Angle;
    double Speed;

    static const Pose ZERO;

};

inline void Pose::setPosition(double x, double y){
    Position.x = x;
    Position.y = y;
}


#endif

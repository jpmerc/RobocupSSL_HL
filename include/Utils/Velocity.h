#ifndef VELOCITY_H
#define VELOCITY_H
#include "Utils/Pose.h"
class Velocity : public Pose
{
public:
    Velocity(Vector2d iPosition, Orientation iOrientation, double iSpeed = 0);
    Velocity(Vector2d iPosition, double iOrientation, double iSpeed = 0);
    Velocity(double iX, double iY, Orientation iOrientation, double iSpeed = 0);
    Velocity(double iX = 0, double iY = 0, double iOrientation = 0, double iSpeed = 0);
    Velocity(const Velocity &other);
    Velocity(const Pose &other);
};

#endif // VELOCITY_H

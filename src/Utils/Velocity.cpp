#include "Utils/Velocity.h"



Velocity::Velocity(Vector2d iPosition, Orientation iOrientation, double iSpeed){
    Position = iPosition;
    Angle = iOrientation,
    Speed = iSpeed;
}

Velocity::Velocity(Vector2d iPosition, double iOrientation, double iSpeed){
    Position = iPosition;
    Angle = Orientation(iOrientation),
    Speed = iSpeed;
}

Velocity::Velocity(double iX, double iY, Orientation iOrientation, double iSpeed){
    Position = Vector2d(iX,iY);
    Angle = iOrientation,
    Speed = iSpeed;
}

Velocity::Velocity(double iX, double iY, double iOrientation, double iSpeed){
    Position = Vector2d(iX,iY);
    Angle = Orientation(iOrientation),
    Speed = iSpeed;
}

Velocity::Velocity(const Pose &other){
    Position = other.Position;
    Angle = other.Angle,
    Speed = other.Speed;
}
Velocity::Velocity(const Velocity &other){
    Position = other.Position;
    Angle = other.Angle,
    Speed = other.Speed;
}

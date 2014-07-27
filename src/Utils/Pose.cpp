
#include "Utils/Pose.h"

const Pose Pose::ZERO(0.0, 0.0, 0.0, 0.0);


Pose::Pose(Vector2d iPosition, Orientation iOrientation, double iSpeed):Position(iPosition),
    Angle(iOrientation),
    Speed(iSpeed){

}

Pose::Pose(Vector2d iPosition, double iOrientation, double iSpeed):Position(iPosition),
    Angle(iOrientation),
    Speed(iSpeed){
}

Pose::Pose(double iX, double iY, Orientation iOrientation, double iSpeed):Position(iX,iY),
    Angle(iOrientation),
    Speed(iSpeed){

}

Pose::Pose(double iX, double iY, double iOrientation, double iSpeed):Position(iX,iY),
    Angle(iOrientation),
    Speed(iSpeed){

}

Pose::Pose(const Pose &other) :
    Position(other.Position),
    Angle(other.Angle),
    Speed(other.Speed){
}


Pose Pose::fromGlobalToRelative(const double iAngleRelative){
    Pose relativePose;
    relativePose.Angle = this->Angle;
    relativePose.Speed = this->Speed;
    relativePose.Position.y = this->Position.y*cos(iAngleRelative) - this->Position.x*sin(iAngleRelative);
    relativePose.Position.x = this->Position.y*sin(iAngleRelative) + this->Position.x*cos(iAngleRelative);
    return relativePose;
}

bool Pose::operator==(const Pose &other) const {
    return Angle == other.Angle && Position == other.Position && Speed == other.Speed;
}

bool Pose::operator!=(const Pose &other) const {
    return Angle != other.Angle || Position != other.Position || Speed != other.Speed;
}


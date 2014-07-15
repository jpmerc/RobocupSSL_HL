/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is a general object to describe everything
 *          that can be moved in the game. For instance, the ball, the player, etc.
 *
 ****************************************************************************/
#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "Utils/Vector2f.h"
#include "Utils/Orientation.h"
#include "Utils/Pose.h"

class MovableObject
{
public:
    virtual Vector2d getPosition(void) const;
    virtual void setPosition(Vector2d iPosition);
//    virtual void translate(const Vector2 &iTranslation);

    virtual Orientation getOrientation(void) const;
    virtual void setOrientation(Orientation iOrientation);
//    virtual void rotate(const Orientation &iOrientation);
//    virtual void rotate(const Degree &iDegree);
//    virtual void rotate(const Radian &iRadian);

    virtual Pose getPose(void) const;
    virtual void setPose(Pose iPose);

    virtual Vector2d getVelocity(void) const;
    virtual void setVelocity(Vector2d iVelocity);
//    virtual void setVelocity(const Degree &iDegree, float iVelocity);
//    virtual void setVelocity(const Radian &iRadian, float iVelocity);

protected:
    Pose mPose;
    Vector2d mVelocity;
};

inline Orientation MovableObject::getOrientation() const{
    return mPose.Angle;
}

inline void MovableObject::setOrientation(Orientation iOrientation){
    mPose.Angle = iOrientation;
}

inline Vector2d MovableObject::getPosition() const{
    return mPose.Position;
}

inline void MovableObject::setPosition(Vector2d iPosition){
    mPose.Position = iPosition;
}

inline Vector2d MovableObject::getVelocity() const{
    return mVelocity;
}

inline void MovableObject::setVelocity(Vector2d iVelocity){
    mVelocity = iVelocity;
}

inline void MovableObject::setPose(Pose iPose){
    mPose = iPose;
}

inline Pose MovableObject::getPose() const{
    return mPose;
}

#endif

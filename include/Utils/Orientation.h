/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to represent the orientation of an object.
 *
 ****************************************************************************/
#ifndef ORIENTATION_H
#define ORIENTATION_H

#include "Vector2d.h"
#include <math.h>

//TODO: Add constructors with Degree and Radian attributes.
//      Add methods to get Degree value and Radian value
//      Overwrite operators

class Orientation
{
public:
    Orientation(double iX, double iY);
    Orientation(Vector2d iVector);
    Orientation(double iAngle = 0);

    void setPolar(double iAngle);
    void setCartesian(Vector2d iCartesian);
    void setCartesian(double iX,double iY);

    double getPolar() const;
    double getMagnitude() const;
    Vector2d getCartesian() const;

    bool operator==(const Orientation &other) const;
    bool operator!=(const Orientation &other) const;

    static const Orientation ZERO;

private:

    double _cartesianToPolar(Vector2d iVector);

    Vector2d mCartesian;
    double mPolar;
    double mMagnitude;

    // special orientations
//    static const Orientation PI;
//    static const Orientation PI_HALF;
//    static const Orientation PI_QUARTER;
//    static const Orientation NEGATIVE_PI;
//    static const Orientation NEGATIVE_PI_HALF;
//    static const Orientation NEGATIVE_PI_QUARTER;
};

inline double Orientation::getMagnitude() const{
    return mMagnitude;
}

inline double Orientation::getPolar() const{
    return mPolar;
}

inline Vector2d Orientation::getCartesian() const{
    return mCartesian;
}

#endif

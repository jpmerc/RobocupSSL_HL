/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with 2D vectors of type double.
 *
 ****************************************************************************/
#ifndef VECTOR_2_D_H
#define VECTOR_2_D_H
#include "Utils/Degree.h"
#include <boost/optional.hpp>


//TODO: Compute dot product and cross product

struct Vector2d {

    template<typename T> Vector2d(const T &other);
    Vector2d(double iX = 0.0f, double iY = 0.0f);
    virtual ~Vector2d();

    void fromPolar(double lenght, double angle);

    double distanceFromCoordinate(const Vector2d &other) const;

    double mag(void) const;
    double magSquared(void) const;
    double angle(void) const;
    double dot(Vector2d iOther) const;
    double cross(const Vector2d &other) const;
    bool isZero() const;
    void rotate(const Vector2d &origin, double angle);
    void rotate(double angle);
    Vector2d rotated(double angle) const;
    double distTo(const Vector2d &other) const;
    Vector2d normalized() const;
    static Vector2d direction(double theta);
    Vector2d perpCW() const;
    Vector2d perpCCW() const;
    double angleTo(const Vector2d& other) const;
    bool nearPoint(const Vector2d &other, double threshold) const;



    Vector2d operator+(const Vector2d &other) const;
    Vector2d operator-(const Vector2d &other) const;
    Vector2d operator*(const Vector2d &other) const;
    Vector2d operator*(const double &scalar) const;
    Vector2d operator/(const Vector2d &other) const;
    Vector2d operator/(const double &scalar) const;
    bool operator==(const Vector2d &other) const;
    bool operator!=(const Vector2d &other) const;
    Vector2d operator-() const;
    Vector2d &operator+=(const Vector2d &other);
    Vector2d &operator-=(const Vector2d &other);
    Vector2d &operator*=(const double &scalar);
    Vector2d &operator*=(const Vector2d &other);
    Vector2d &operator/=(const double &scalar);
    Vector2d &operator/=(const Vector2d &other);


    double x;
    double y;

    //Special points
    static const Vector2d ZERO;
    static const Vector2d UNIT_X;
    static const Vector2d UNIT_Y;
    static const Vector2d NEGATIVE_UNIT_X;
    static const Vector2d NEGATIVE_UNIT_Y;
    static const Vector2d UNIT_SCALE;
};

inline bool Vector2d::isZero() const{
    if(x == 0.0 && y == 0.0){
        return true;
    }
    return false;
}

#endif

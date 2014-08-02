/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with 2D vectors of type float.
 *
 ****************************************************************************/
#ifndef VECTOR_2_F_H
#define VECTOR_2_F_H
#include "Utils/Degree.h"
#include "Vector2d.h"
#include <boost/optional.hpp>

//TODO: Compute dot product and cross product

struct Vector2f {
    //Vector2f();
    Vector2f(const Vector2d &other);
    template<class T> Vector2f(const T &other);
    Vector2f(float iX = 0.0f, float iY = 0.0f);
    virtual ~Vector2f();

    float mag(void) const;
    float magSquared(void) const;
    double angle(void) const;
    float dot(Vector2f iOther) const;
    float cross(const Vector2f &other) const;
    bool isZero() const;
    void rotate(const Vector2f &origin, float angle);
    void rotate(float angle);
    Vector2f rotated(float angle) const;
    float distTo(const Vector2f &other) const;
    Vector2f normalized() const;
    static Vector2f direction(float theta);
    Vector2f perpCW() const;
    Vector2f perpCCW() const;
    float angleTo(const Vector2f& other) const;
    bool nearPoint(const Vector2f &other, float threshold) const;
    void clamp(float max);


    Vector2f operator+(const Vector2f &other) const;
    Vector2f operator-(const Vector2f &other) const;
    Vector2f operator*(const Vector2f &other) const;
    Vector2f operator*(const float &scalar) const;
    Vector2f operator/(const Vector2f &other) const;
    Vector2f operator/(const float &scalar) const;
    bool operator==(const Vector2f &other) const;
    bool operator!=(const Vector2f &other) const;
    Vector2f operator-() const;
    Vector2f &operator+=(const Vector2f &other);
    Vector2f &operator-=(const Vector2f &other);
    Vector2f &operator*=(const float &scalar);
    Vector2f &operator*=(const Vector2f &other);
    Vector2f &operator/=(const float &scalar);
    Vector2f &operator/=(const Vector2f &other);


    float x;
    float y;

    //Special points
    static const Vector2f ZERO;
    static const Vector2f UNIT_X;
    static const Vector2f UNIT_Y;
    static const Vector2f NEGATIVE_UNIT_X;
    static const Vector2f NEGATIVE_UNIT_Y;
    static const Vector2f UNIT_SCALE;
};

inline bool Vector2f::isZero() const{
    if(x == 0.0 && y == 0.0){
        return true;
    }
    return false;
}
#endif

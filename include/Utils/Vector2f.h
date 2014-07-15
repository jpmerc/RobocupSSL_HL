/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with 2D vectors of type float.
 *
 ****************************************************************************/
#ifndef VECTOR_2_F_H
#define VECTOR_2_F_H

//TODO: Compute dot product and cross product

struct Vector2f {
    Vector2f(const Vector2f &other);
    Vector2f(float iX = 0.0f, float iY = 0.0f);
    virtual ~Vector2f();

    float length(void);
    double angle(void);

    Vector2f operator+(const Vector2f &other) const;
    Vector2f operator-(const Vector2f &other) const;
    Vector2f operator*(const Vector2f &other) const;
    Vector2f operator*(const float &scalar) const;
    Vector2f operator/(const Vector2f &other) const;
    Vector2f operator/(const float &scalar) const;
    bool operator==(const Vector2f &other) const;
    bool operator!=(const Vector2f &other) const;

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

#endif

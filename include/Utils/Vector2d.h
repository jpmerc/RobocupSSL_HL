/****************************************************************************
 *Author :  Ian Létourneau <ian.letourneau.1@ulaval.ca>
 *
 *Purpose:  This module is an utility to interact with 2D vectors of type double.
 *
 ****************************************************************************/
#ifndef VECTOR_2_D_H
#define VECTOR_2_D_H

//TODO: Compute dot product and cross product

struct Vector2d {
    Vector2d(const Vector2d &other);
    Vector2d(double iX = 0.0, double iY = 0.0);
    virtual ~Vector2d();

    double length(void) const;
    double angle(void) const;
    bool isZero(void) const;
    void fromPolar(double lenght, double angle);

    Vector2d operator+(const Vector2d &other) const;
    Vector2d operator-(const Vector2d &other) const;
    Vector2d operator*(const Vector2d &other) const;
    Vector2d operator*(const float &scalar) const;
    Vector2d operator/(const Vector2d &other) const;
    Vector2d operator/(const float &scalar) const;
    bool operator==(const Vector2d &other) const;
    bool operator!=(const Vector2d &other) const;

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

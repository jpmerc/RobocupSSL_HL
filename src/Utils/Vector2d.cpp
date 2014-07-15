#include "Utils/Vector2d.h"

#include <math.h>

const Vector2d Vector2d::ZERO(0.0, 0.0);
const Vector2d Vector2d::UNIT_X(1.0, 0.0);
const Vector2d Vector2d::UNIT_Y(0.0, 1.0);
const Vector2d Vector2d::NEGATIVE_UNIT_X(-1.0, 0.0);
const Vector2d Vector2d::NEGATIVE_UNIT_Y(0.0, -1.0);
const Vector2d Vector2d::UNIT_SCALE(1.0, 1.0);

Vector2d::Vector2d(const Vector2d &other) :
    x(other.x),
    y(other.y){
}

Vector2d::~Vector2d(){
}

Vector2d::Vector2d(double iX, double iY) :
    x(iX),
    y(iY){
}

void Vector2d::fromPolar(double lenght, double angle){
    x = lenght * cos(angle);
    y = lenght * sin(angle);
}

double Vector2d::length(void) const{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2d::angle(void) const{
    return atan2(y, x);
}

Vector2d Vector2d::operator+(const Vector2d &other) const{
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator-(const Vector2d &other) const{
    return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::operator*(const Vector2d &other) const{
    return Vector2d(x * other.x, y * other.y);
}

Vector2d Vector2d::operator*(const float &scalar) const{
    return Vector2d(x * scalar, y * scalar);
}

Vector2d Vector2d::operator/(const Vector2d &other) const{
    if(other == Vector2d::ZERO){
        return *this;
    }

    float lX = (other.x == 0.0) ? x : x / other.x;
    float lY = (other.y == 0.0) ? y : y / other.y;

    return Vector2d(lX, lY);
}

Vector2d Vector2d::operator/(const float &scalar) const{
    if(scalar == 0.0){
        return *this;
    }

    return Vector2d(x / scalar, y / scalar);
}

bool Vector2d::operator==(const Vector2d &other) const {
    return x == other.x && y == other.y;
}

bool Vector2d::operator!=(const Vector2d &other) const {
    return x != other.x || y != other.y;
}

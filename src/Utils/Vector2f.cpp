#include "Utils/Vector2f.h"

#include <math.h>

const Vector2f Vector2f::ZERO(0.0f, 0.0f);
const Vector2f Vector2f::UNIT_X(1.0f, 0.0f);
const Vector2f Vector2f::UNIT_Y(0.0f, 1.0f);
const Vector2f Vector2f::NEGATIVE_UNIT_X(-1.0f, 0.0f);
const Vector2f Vector2f::NEGATIVE_UNIT_Y(0.0f, -1.0f);
const Vector2f Vector2f::UNIT_SCALE(1.0f, 1.0f);

Vector2f::Vector2f(const Vector2f &other) :
    x(other.x),
    y(other.y){
}

Vector2f::~Vector2f(){
}

Vector2f::Vector2f(float iX, float iY) :
    x(iX),
    y(iY){
}

float Vector2f::length(void){
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2f::angle(void){
    return atan2(y, x);
}

Vector2f Vector2f::operator+(const Vector2f &other) const{
    return Vector2f(x + other.x, y + other.y);
}

Vector2f Vector2f::operator-(const Vector2f &other) const{
    return Vector2f(x - other.x, y - other.y);
}

Vector2f Vector2f::operator*(const Vector2f &other) const{
    return Vector2f(x * other.x, y * other.y);
}

Vector2f Vector2f::operator*(const float &scalar) const{
    return Vector2f(x * scalar, y * scalar);
}

Vector2f Vector2f::operator/(const Vector2f &other) const{
    if(other == Vector2f::ZERO){
        return *this;
    }

    float lX = (other.x == 0.0f) ? x : x / other.x;
    float lY = (other.y == 0.0f) ? y : y / other.y;

    return Vector2f(lX, lY);
}

Vector2f Vector2f::operator/(const float &scalar) const{
    if(scalar == 0.0f){
        return *this;
    }

    return Vector2f(x / scalar, y / scalar);
}

bool Vector2f::operator==(const Vector2f &other) const {
    return x == other.x && y == other.y;
}

bool Vector2f::operator!=(const Vector2f &other) const {
    return x != other.x || y != other.y;
}

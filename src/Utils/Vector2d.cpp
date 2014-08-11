
#include "Utils/Vector2d.h"

#include <math.h>

const Vector2d Vector2d::ZERO(0.0f, 0.0f);
const Vector2d Vector2d::UNIT_X(1.0f, 0.0f);
const Vector2d Vector2d::UNIT_Y(0.0f, 1.0f);
const Vector2d Vector2d::NEGATIVE_UNIT_X(-1.0f, 0.0f);
const Vector2d Vector2d::NEGATIVE_UNIT_Y(0.0f, -1.0f);
const Vector2d Vector2d::UNIT_SCALE(1.0f, 1.0f);

//Vector2d::Vector2d()
//{
//    x = y = 0;
//}

//Vector2d::Vector2d(const Vector2f &other){
//    x = other.x;
//    y = other.y;
//}


template<typename T>
Vector2d::Vector2d(const T &other){
    x = other.x;
    y = other.y;
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

double Vector2d::distanceFromCoordinate(const Vector2d &other) const{
    return sqrt(pow(other.x - x,2) + pow(other.y - y,2));
}



double Vector2d::mag(void) const{
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2d::magSquared(void) const{
    return pow(x, 2) + pow(y, 2);
}

double Vector2d::angle(void) const{
    return atan2(y, x);
}

double Vector2d::dot(Vector2d iOther) const
{
    return x * iOther.x + y * iOther.y;
}

double Vector2d::cross(const Vector2d &other) const
{
    return x * other.y - y * other.x;
}


void Vector2d::rotate(const Vector2d &origin, double angle)
{
	*this -= origin;
	rotate(angle);
	*this += origin;
}

void Vector2d::rotate(double angle)
{
	double newX = x * cos(angle * DEGREES_TO_RADIANS) - y * sin(angle * DEGREES_TO_RADIANS);
	double newY = y * cos(angle * DEGREES_TO_RADIANS) + x * sin(angle * DEGREES_TO_RADIANS);
	x = newX;
	y = newY;
}


/**
 * Like rotate(), but returns a new vector instead of changing *this
 */
Vector2d Vector2d::rotated(double angle) const
{
	double newX = x * cos(angle * DEGREES_TO_RADIANS) - y * sin(angle * DEGREES_TO_RADIANS);
	double newY = y * cos(angle * DEGREES_TO_RADIANS) + x * sin(angle * DEGREES_TO_RADIANS);
	return Vector2d(newX, newY);
}

double Vector2d::distTo(const Vector2d &other) const
{
	Vector2d delta = other - *this;
	return delta.mag();
}

Vector2d Vector2d::normalized() const
{
	double m = this->mag();
	if (m == 0)
	{
		return Vector2d(0, 0);
	}

	return Vector2d(x / m , y / m);
}

Vector2d Vector2d::direction(double theta)
{
	return Vector2d(cos(theta), sin(theta));
}

/** returns the perpendicular to the point, Clockwise */
Vector2d Vector2d::perpCW() const
{
	return Vector2d(y, -x);
}

Vector2d Vector2d::perpCCW() const
{
	return Vector2d(-y, x);
}

/** returns the angle between the two points (radians) */
double Vector2d::angleTo(const Vector2d& other) const
{
	return acos(this->normalized().dot(other.normalized()));
}

/**
* Returns true if this point is within the given distance (threshold) of (pt)
*/
bool Vector2d::nearPoint(const Vector2d &other, double threshold) const
{
    return (*this - other).mag() <= (threshold * threshold);
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

Vector2d Vector2d::operator*(const double &scalar) const{
    return Vector2d(x * scalar, y * scalar);
}

Vector2d Vector2d::operator/(const Vector2d &other) const{
    if(other == Vector2d::ZERO){
        return *this;
    }

    double lX = (other.x == 0.0f) ? x : x / other.x;
    double lY = (other.y == 0.0f) ? y : y / other.y;

    return Vector2d(lX, lY);
}

Vector2d Vector2d::operator/(const double &scalar) const{
    if(scalar == 0.0d){
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

Vector2d Vector2d::operator-() const
{
    return Vector2d(-x, -y);
}

Vector2d &Vector2d::operator+=(const Vector2d &other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2d &Vector2d::operator-=(const Vector2d &other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}
Vector2d &Vector2d::operator*=(const double &iScalar)
{
	x *= iScalar;
	y *= iScalar;

	return *this;
}

Vector2d &Vector2d::operator/=(const double &iScalar)
{
	if(iScalar != 0.0d){
		x /= iScalar;
		y /= iScalar;
	}

	return *this;
}


Vector2d &Vector2d::operator*=(const Vector2d &other)
{
	x *= other.x;
	y *= other.y;

	return *this;
}

Vector2d &Vector2d::operator/=(const Vector2d &other)
{
	x /= other.x;
	y /= other.y;

	return *this;
}

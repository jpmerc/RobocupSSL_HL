#include "Utils/Vector2f.h"

#include <math.h>

const Vector2f Vector2f::ZERO(0.0f, 0.0f);
const Vector2f Vector2f::UNIT_X(1.0f, 0.0f);
const Vector2f Vector2f::UNIT_Y(0.0f, 1.0f);
const Vector2f Vector2f::NEGATIVE_UNIT_X(-1.0f, 0.0f);
const Vector2f Vector2f::NEGATIVE_UNIT_Y(0.0f, -1.0f);
const Vector2f Vector2f::UNIT_SCALE(1.0f, 1.0f);

//Vector2f::Vector2f()
//{
//    x = y = 0;
//}

Vector2f::Vector2f(const Vector2d &other)
{
    x = other.x;
    y = other.y;
}

template<class T> Vector2f::Vector2f(const T &other)
{
    x = other.x;
    y = other.y;
}

Vector2f::~Vector2f(){
}

Vector2f::Vector2f(float iX, float iY) :
    x(iX),
    y(iY){
}

float Vector2f::mag(void) const{
    return sqrt(pow(x, 2) + pow(y, 2));
}

float Vector2f::magSquared(void) const{
    return pow(x, 2) + pow(y, 2);
}

double Vector2f::angle(void) const{
    return atan2(y, x);
}

float Vector2f::dot(Vector2f iOther) const
{
    return x * iOther.x + y * iOther.y;
}

float Vector2f::cross(const Vector2f &other) const
{
    return x * other.y - y * other.x;
}


void Vector2f::rotate(const Vector2f &origin, float angle)
{
	*this -= origin;
	rotate(angle);
	*this += origin;
}

void Vector2f::rotate(float angle)
{
	float newX = x * cos(angle * DEGREES_TO_RADIANS) - y * sin(angle * DEGREES_TO_RADIANS);
	float newY = y * cos(angle * DEGREES_TO_RADIANS) + x * sin(angle * DEGREES_TO_RADIANS);
	x = newX;
	y = newY;
}


/**
 * Like rotate(), but returns a new vector instead of changing *this
 */
Vector2f Vector2f::rotated(float angle) const
{
	float newX = x * cos(angle * DEGREES_TO_RADIANS) - y * sin(angle * DEGREES_TO_RADIANS);
	float newY = y * cos(angle * DEGREES_TO_RADIANS) + x * sin(angle * DEGREES_TO_RADIANS);
	return Vector2f(newX, newY);
}

float Vector2f::distTo(const Vector2f &other) const
{
	Vector2f delta = other - *this;
	return delta.mag();
}

Vector2f Vector2f::normalized() const
{
	float m = this->mag();
	if (m == 0)
	{
		return Vector2f(0, 0);
	}

	return Vector2f(x / m , y / m);
}

Vector2f Vector2f::direction(float theta)
{
	return Vector2f(cos(theta), sin(theta));
}

/** returns the perpendicular to the point, Clockwise */
Vector2f Vector2f::perpCW() const
{
	return Vector2f(y, -x);
}

Vector2f Vector2f::perpCCW() const
{
	return Vector2f(-y, x);
}

/** returns the angle between the two points (radians) */
float Vector2f::angleTo(const Vector2f& other) const
{
	return acos(this->normalized().dot(other.normalized()));
}

/**
* Returns true if this point is within the given distance (threshold) of (pt)
*/
bool Vector2f::nearPoint(const Vector2f &other, float threshold) const
{
    return (*this - other).mag() <= (threshold * threshold);
}

void Vector2f::clamp(float max)
{
	if (mag() > max) {
		float ratio = mag() / max;
		x = x / ratio;
		y = y / ratio;
	}
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

Vector2f Vector2f::operator-() const
{
    return Vector2f(-x, -y);
}

Vector2f &Vector2f::operator+=(const Vector2f &other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2f &Vector2f::operator-=(const Vector2f &other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}
Vector2f &Vector2f::operator*=(const float &iScalar)
{
	x *= iScalar;
	y *= iScalar;

	return *this;
}

Vector2f &Vector2f::operator/=(const float &iScalar)
{
	x /= iScalar;
	y /= iScalar;

	return *this;
}


Vector2f &Vector2f::operator*=(const Vector2f &other)
{
	x *= other.x;
	y *= other.y;

	return *this;
}

Vector2f &Vector2f::operator/=(const Vector2f &other)
{
	x /= other.x;
	y /= other.y;

	return *this;
}

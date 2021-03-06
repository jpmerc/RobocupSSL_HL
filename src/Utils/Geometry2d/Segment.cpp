
#include "Utils/Geometry2d/Segment.hpp"
#include "Utils/Vector2f.h"

using namespace std;
using namespace Geometry2d;

Rect Segment::bbox() const
{
	Rect bbox;

	bbox.pt[0].x = min(pt[0].x, pt[1].x);
	bbox.pt[0].y = min(pt[0].y, pt[1].y);
	bbox.pt[1].x = max(pt[0].x, pt[1].x);
	bbox.pt[1].y = max(pt[0].y, pt[1].y);

	return bbox;
}

float Segment::distTo(const Vector2f &other) const
{
	// Calculate the distance in the delta direction of other
	// with respect to the segment's first end Vector2f.
	 Vector2f dp = pt[1] - pt[0];
	float d = dp.dot(other - pt[0]);

	if (d < 0)
	{
		// Nearest Vector2f on the segment is pt[0]
		return other.distTo(pt[0]);
	} else if (d > dp.magSquared())
	{
		// Nearest Vector2f on the segment is pt[1]
		return other.distTo(pt[1]);
	} else {
		// Nearest Vector2f on the segment is the nearest Vector2f on the segment's line
		return Line::distTo(other);
	}
}

bool Segment::intersects(const Segment &other, Vector2f *intr) const
{
	// From Mathworld:
	//	http://mathworld.wolfram.com/Line2d-Line2dIntersection.html

	float x1 = pt[0].x;
	float y1 = pt[0].y;
	float x2 = pt[1].x;
	float y2 = pt[1].y;
	float x3 = other.pt[0].x;
	float y3 = other.pt[0].y;
	float x4 = other.pt[1].x;
	float y4 = other.pt[1].y;

	float denom = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
	if (denom == 0)
    {
		return false;
    }

	float deta = x1 * y2 - y1 * x2;
	float detb = x3 * y4 - y3 * x4;

	float ix = (deta * (x3 - x4) - (x1 - x2) * detb) / denom;
	float iy = (deta * (y3 - y4) - (y1 - y2) * detb) / denom;

    Vector2f ip(ix, iy);
    
    Vector2f da = delta();
    float ta = (ip - pt[0]).dot(da) / da.magSquared();
    
    Vector2f db = other.delta();
    float tb = (ip - other.pt[0]).dot(db) / db.magSquared();
    
    if (ta < 0 || ta > 1 || tb < 0 || tb > 1)
    {
        return false;
    }

	if (intr)
	{
		intr->x = ix;
		intr->y = iy;
	}

	return true;
}

std::shared_ptr< Vector2f> Segment::intersection(const Segment &other) {
	 Vector2f Vector2fOut;
	bool doesIt = intersects(other, & Vector2fOut);
	if (doesIt) {
		return std::make_shared< Vector2f>( Vector2fOut);
	} else {
		return nullptr;
	}
}

bool Segment::intersects(const Circle& circle) const
{
	 Vector2f pCir(circle.center.x, circle.center.y);
	 Vector2f delta = pt[1] - pt[0];
	
	float top = delta.x * (pCir.x - pt[0].x) + (pCir.y - pt[0].y) * delta.y;
	
	float u = fabs(top)/delta.magSquared();
	
	if (u>0 && u<1)
	{
		float dist = distTo(pCir);
		if (dist <= circle.radius())
		{
			return true;
		}
	}
	
	return false;
}

bool Segment::nearPoint(const Vector2f & point, float threshold) const
{
	const Vector2f &p1 = pt[0];
	const Vector2f &p2 = pt[1];
	
	Vector2f delta = p2 - p1;
	float top = delta.x * (p1.y - point.y) - (p1.x - point.x) * delta.y;
	float delta_magsq = delta.magSquared();
	float dist = fabs(top) / sqrtf(delta_magsq);

	// Check smallest distance from this Vector2f to the line
	if (dist > threshold)
    {
		return false;
    }

	 Vector2f d1 = point - p1;
	 Vector2f d2 = point - p2;
	float tsq = threshold * threshold;

	// Check distance to each end Vector2f
	if (d1.magSquared() <= tsq || d2.magSquared() <= tsq)
    {
		return true;
    }

	// Calculate the position between the end Vector2fs of the Vector2f on
	// the line nearest this Vector2f.
	// In the result (d), p1 maps to 0 and p2 maps to 1.
	float d = (d1.x * delta.x + d1.y * delta.y) / delta_magsq;

	return d >= 0 && d <= 1;
}

bool Segment::nearPointPerp(const Vector2f & point, float threshold) const {
	const Vector2f &p1 = pt[0];
	const Vector2f &p2 = pt[1];

	Vector2f delta = p2 - p1;
	float top = delta.x * (p1.y - point.y) - (p1.x - point.x) * delta.y;
	float delta_magsq = delta.magSquared();
	float dist = fabs(top) / sqrtf(delta_magsq);

	// Check smallest distance from this Vector2f to the line
	if (dist > threshold)
    {
		return false;
    }

     Vector2f d1 = point - p1;

	// Calculate the position between the end Vector2fs of the Vector2f on
	// the line nearest this Vector2f.
	// In the result (d), p1 maps to 0 and p2 maps to 1.
	float d = (d1.x * delta.x + d1.y * delta.y) / delta_magsq;

	return d >= 0 && d <= 1;
}

 Vector2f Segment::nearestPoint(const Vector2f& p) const
{
	const float magsq = delta().magSquared();
	
	Vector2f v_hat = delta()/sqrt(magsq);
	float t = v_hat.dot(p - pt[0]);
	
	if (t < 0)
	{
		t =0;
	}
	else if (t > magsq)
	{
		t = magsq;
	}
	
    return pt[0] + v_hat * t;
}

bool Segment::nearSegment(const Segment &other, float threshold) const
{
    bool ret = other.nearPoint(pt[0], threshold) ||
               other.nearPoint(pt[1], threshold) ||
               nearPoint(other.pt[0], threshold) ||
               nearPoint(other.pt[1], threshold) ||
               intersects(other);
    return ret;
}

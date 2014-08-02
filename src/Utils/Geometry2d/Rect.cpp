#include "Utils/Geometry2d/Rect.hpp"
#include "Utils/Geometry2d/Point.hpp"
#include "Utils/Geometry2d/Segment.hpp"

using namespace std;
using namespace Geometry2d;

Shape *Rect::clone() const {
	return new Rect(*this);
}

bool Rect::intersects(const Rect &other) const
{
	if (other.maxx() < minx() || other.minx() > maxx() || other.maxy() < miny() || other.miny() > maxy())
    {
		return false;
	} else {
        return true;
    }
}

bool Rect::contains(const Rect &other) const
{
	//return other.pt[0].inRect(*this) && other.pt[1].inRect(*this);
	return this->contains(other.pt[0]) && this->contains(other.pt[1]);
}

bool Rect::contains(const Vector2f &point) const
{
	float minx, miny, maxx, maxy;

	if (pt[0].x < pt[1].x)
	{
		minx = pt[0].x;
		maxx = pt[1].x;
	} else {
		minx = pt[1].x;
		maxx = pt[0].x;
	}

	if (pt[0].y < pt[1].y)
	{
		miny = pt[0].y;
		maxy = pt[1].y;
	} else {
		miny = pt[1].y;
		maxy = pt[0].y;
	}
	
	return point.x >= minx && point.x <= maxx && point.y >= miny && point.y <= maxy;
}

bool Rect::hit(const Segment &seg) const {
	return contains(seg.pt[0])
			|| contains(seg.pt[1])
			|| seg.intersects(Segment(Vector2f(minx(), miny()), Vector2f(minx(), maxy())))
			|| seg.intersects(Segment(Vector2f(minx(), miny()), Vector2f(maxx(), miny())))
			|| seg.intersects(Segment(Vector2f(minx(), maxy()), Vector2f(maxx(), maxy())))
			|| seg.intersects(Segment(Vector2f(maxx(), maxy()), Vector2f(maxx(), miny())));
}

void Rect::expand(const Vector2f &p)
{
	pt[0].x = min(pt[0].x, p.x);
	pt[0].y = min(pt[0].y, p.y);
	pt[1].x = max(pt[1].x, p.x);
	pt[1].y = max(pt[1].y, p.y);
}

void Rect::expand(const Rect &rect)
{
	expand(rect.pt[0]);
	expand(rect.pt[1]);
}

bool Rect::nearSegment(const Segment &seg, float threshold) const
{
	const Vector2f &p1 = seg.pt[0];
	const Vector2f &p2 = seg.pt[1];

	// Simpler case if this rect is degenerate
	if (pt[0] == pt[1])
		//return pt[0].nearSegment(seg, threshold);
		return seg.nearPoint(pt[0], threshold);

	// If either endpoint is inside this rect the
	// the segment intersects it.
	if (this->contains(p1) || this->contains(p2))
		return true;

	// If any corner of this rect is near the segment,
	// then the segment is near this rect.
	Vector2f ur = Vector2f(pt[1].x, pt[0].y);
	Vector2f ll = Vector2f(pt[0].x, pt[1].y);
	if (seg.nearPoint(pt[0], threshold)
		   || seg.nearPoint(ur, threshold)
		   || seg.nearPoint(ll, threshold)
		   || seg.nearPoint(pt[1], threshold))
	{
		return true;
	}

	Segment edge[4] = {
		Segment(pt[0], ur),
		Segment(ur, pt[1]),
		Segment(pt[0], ll),
		Segment(ll, pt[1])
	};

	// If either endpoint of the segment is near an edge
	// of the rect, then the segment is near this rect.
	for (int i = 0; i < 4; i++)
	{
		if (edge[i].nearPoint(pt[0], threshold) || edge[i].nearPoint(pt[1], threshold))
			return true;
	}

	// If any edge of this rect intersects the segment,
	// then the segment is near this rect.
	for (int i = 0; i < 4; i++)
	{
		if (seg.intersects(edge[i]))
			return true;
	}

	return false;
}

bool Rect::nearPoint(const Vector2f &other, float threshold) const
{
	// Simpler case if this rect is degenerate
	if (pt[0] == pt[1])
		return pt[0].distTo(other) < threshold;

	// If the Vector2f is inside this rect then it is near it.
	if (this->contains(other))
		return true;

	Vector2f ur = Vector2f(pt[1].x, pt[0].y);
	Vector2f ll = Vector2f(pt[0].x, pt[1].y);
	Segment edge[4] = {
		Segment(pt[0], ur),
		Segment(ur, pt[1]),
		Segment(pt[0], ll),
		Segment(ll, pt[1])
	};

	// If any edge of this rect is near the Vector2f, then the
	// Vector2f is near the rect.
	for (int i = 0; i < 4; i++)
	{
		if (edge[i].nearPoint(other,threshold))
			return true;
	}

	return false;
}

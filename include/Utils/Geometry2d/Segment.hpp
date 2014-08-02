
#pragma once

#include "Rect.hpp"
#include "Utils/Vector2f.h"
#include "Line.hpp"
#include "Circle.hpp"

#include <memory>

namespace Geometry2d
{	
	class Segment: public Line
	{
		public:
			Segment() {}
			
			Segment(const Segment &other): Line(other) {}
			Segment(Vector2f p1, Vector2f p2): Line(p1, p2) {}
			
			Segment &operator+=(const Vector2f &delta)
			{
				pt[0] += delta;
				pt[1] += delta;
				
				return *this;
			}
			
			Vector2f center() const
			{
				return (pt[0] + pt[1]) / 2;
			}
			
			/* returns a bounding box of type Rect */
			Rect bbox() const;
			
			/* returns the distance to Vector2f other */
			float distTo(const Vector2f &other) const;
			
			/* returns the length of the segment */
			float length() const { return (pt[1] - pt[0]).mag(); }
			
			bool nearPoint(const Vector2f &Vector2f, float threshold) const;
			bool nearPointPerp(const Vector2f &Vector2f, float threshold) const;
			bool nearSegment(const Segment &other, float threshold) const;
			
			/** find the nearest Vector2f on the segment given @a p */
			Vector2f nearestPoint(const Vector2f& p) const;
			
			bool intersects(const Segment &other, Vector2f *intr = 0) const;
			bool intersects(const Circle& circle) const;

			//	Same as the segment intersection above, but returns the intersection
			//	Vector2f or nullptr rather than returning a bool and setting an out variable
			//	This was added to be used with python code, but is useful in c++ as well
			std::shared_ptr<Vector2f> intersection(const Segment &other);
	};
}

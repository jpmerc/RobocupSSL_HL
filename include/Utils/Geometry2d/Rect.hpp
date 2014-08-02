#pragma once

#include "Shape.hpp"
#include "Utils/Vector2f.h"

#include <algorithm>

namespace Geometry2d
{
	class Segment;
	
	class Rect : public Shape
	{
		public:
			Rect() {}

            Rect(const Vector2f &p1)
            {
                pt[0] = pt[1] = p1;
            }

			Rect(const Vector2f &p1, const Vector2f &p2)
			{
				pt[0] = p1;
				pt[1] = p2;
			}

			Rect(const Rect &other) {
				pt[0] = other.pt[0];
				pt[1] = other.pt[1];
			}

			Shape *clone() const;

			Rect &operator+=(const Vector2f &offset)
			{
				pt[0] += offset;
				pt[1] += offset;

				return *this;
			}

			Rect &operator-=(const Vector2f &offset)
			{
				pt[0] -= offset;
				pt[1] -= offset;

				return *this;
			}

			Rect operator+(const Vector2f &offset)
			{
				return Rect(pt[0] + offset, pt[1] + offset);
			}

			Rect operator*(float s)
			{
				return Rect(pt[0] * s, pt[1] * s);
			}

			Rect &operator*=(float s)
			{
				pt[0] *= s;
				pt[1] *= s;

				return *this;
			}
			
			bool contains(const Vector2f &other) const;
			bool contains(const Rect &other) const;

			bool containsPoint(const Vector2f &other) const {
				return contains(other);
			}


			bool hit(const Vector2f &pt) const {
	        	return contains(pt);
	        }

	        bool hit(const Segment &seg) const;

			Vector2f center() const { return (pt[0] + pt[1]) / 2; }

			void expand(const Vector2f &pt);
			void expand(const Rect &rect);

			float minx() const { return std::min(pt[0].x, pt[1].x); }
			float miny() const { return std::min(pt[0].y, pt[1].y); }
			float maxx() const { return std::max(pt[0].x, pt[1].x); }
			float maxy() const { return std::max(pt[0].y, pt[1].y); }
			
			bool nearPoint(const Vector2f &pt, float threshold) const;
			bool nearSegment(const Segment &seg, float threshold) const;
			
			bool intersects(const Rect &other) const;
			
			Vector2f pt[2];
	};
}

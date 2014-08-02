#pragma once

#include "Utils/Vector2f.h"
#include "TransformMatrix.hpp"

namespace Geometry2d
{
    class Circle;
    
	class Line
	{
		public:
			Line() {}
			
			Line(const Line &other)
			{
				pt[0] = other.pt[0];
				pt[1] = other.pt[1];
			}
			
			Line(Vector2f p1, Vector2f p2)
			{
				pt[0] = p1;
				pt[1] = p2;
			}

            Vector2f delta() const
            {
                return pt[1] - pt[0];
            }

			/**
			returns the shortest distance between the line and a Vector2f
			@param other the Vector2f to find the distance to
			@return the distance to the Vector2f from the line
			*/
			float distTo(const Vector2f &other) const;
			
			/**
			Applies a transformation matrix to the line.
			@param t the transformation matrix to perform on the line
			*/
			void transform(const TransformMatrix &t)
			{
				pt[0] = t * pt[0];
				pt[1] = t * pt[1];
			}
			
			/**
			Test for line intersections.
			If the two lines intersect, then the function returns true, else false.
			Also, if the lines intersect, then intr is set to the intersection Vector2f.
			@param other the line to test for intersection with
			@param intr set to the intersection Vector2f if the lines intersect
			@return true if the lines intersect, false otherwise
			*/
			bool intersects(const Line &other, Vector2f *intersection = 0) const;
			
			/** returns the Vector2fs of intersection b/t circle and line */
			bool intersects(const Circle& circle, Vector2f* p1 = 0, Vector2f* p2 = 0) const;
            
			/**
			 * tells you which side of the line you are on
			 * @return the sine of the non-zero portion of the cross product
			 */
			float Vector2fSide(const Vector2f &p) const
            {
                Vector2f d = delta();
                Vector2f v = p - pt[0];
                
                return (d.x * v.y - v.x * d.y);
            }
			
			/**
			 * Returns the Vector2f on the line closest to p.
			 */
			Vector2f nearestPoint(Vector2f p) const;
			
			/** the line consists of two Vector2fs */
			Vector2f pt[2];
	};
}

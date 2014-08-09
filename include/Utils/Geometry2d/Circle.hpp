#pragma once

#include <memory>
#include "Shape.hpp"
#include "Utils/Vector2f.h"
#include "Line.hpp"
#include <Utils/Constants.hpp>

namespace Geometry2d
{
    class Circle : public Shape
    {
    public:
        Circle()
        {
            _r = -1;
            _rsq = -1;
        }
        
        Circle(const Vector2f &c, float r)
        {
            center = c;
            _r = r;
            _rsq = -1;
        }

        Circle(const Circle &other) {
            center = other.center;
            _r = other.radius();
        }

        Shape *clone() const;
        

        // Both radius and radius-squared are stored, since some operations are more
        // efficient with one or the other.
        // As long as one is specified, the other is calculated lazily.
        
        // Radius squared
        float radius_sq() const
        {
            if (_rsq < 0 && _r >= 0)
            {
                _rsq = _r * _r;
            }
            
            return _rsq;
        }
        
        void radius_sq(float value)
        {
            _rsq = value;
            _r = -1;
        }
        
        // Radius
        float radius() const
        {
            if (_r < 0 && _rsq >= 0)
            {
                _r = sqrtf(_rsq);
            }
            
            return _r;
        }
        
        void radius(float value)
        {
            _r = value;
            _rsq = -1;
        }
        
        bool containsPoint(const Vector2f &pt) const;

        bool hit(const Vector2f &pt) const;

        bool hit(const Segment &pt) const;
        
        // Returns the number of Vector2fs at which this circle intersects the given circle.
        // i must be null or Vector2f to two Vector2fs.
        // Only the first n Vector2fs in i are modified, where n is the return value.
        int intersects(Circle &other, Vector2f *i = 0) const;
        
        // Returns the number of Vector2fs at which this circle intersects the given line.
        // i must be null or Vector2f to two Vector2fs.
        // Only the first n Vector2fs in i are modified, where n is the return value.
        int intersects(const Line &line, Vector2f *i = 0) const;
        
        bool tangentPoints(const Vector2f &src,
                Vector2f* p1 = 0, Vector2f* p2 = 0) const;
        
        // finds the Vector2f on the circle closest to P
        Vector2f nearestPoint(const Vector2f &P) const;

        Vector2f center;
        std::shared_ptr<Geometry2d::Shape> getPointer();

        
    protected:
        // Radius
        mutable float _r;
        
        // Radius squared
        mutable float _rsq;
    };
}

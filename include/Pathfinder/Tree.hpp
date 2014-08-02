#pragma once

#include <list>

#include <Utils/Geometry2d/Segment.hpp>
#include "Path.hpp"

namespace Planning
{
	/** base tree class for rrt trees
	 *  Tree can be grown in different ways */
	class Tree
	{
		public:
			
			/** base class for a tree point */
			class Point
			{
				public:
					Point(const  Vector2f& pos, Point* parent);
					
					//field position of the point
					 Vector2f pos;
					
					// Which obstacles contain this point
					std::set<std::shared_ptr<Geometry2d::Shape>> hit;
					
					//velocity information (used by dynamic tree)
					 Vector2f vel;
					
					bool leaf;
					
					inline Point* parent() const { return _parent; }
					
					void addEdges(std::list<Geometry2d::Segment>& edges);
					
				private:
					std::list<Point *> children;
					Point* _parent;
			};
			
			Tree();
			virtual ~Tree();
			
			/** cleanup the tree */
			void clear();
			
			void init(const  Vector2f &start, const Geometry2d::CompositeShape *obstacles);
			
			/** find the point of the tree closest to @a pt */
			Point* nearest( Vector2f pt);
			
			/** grow the tree in the direction of pt
			 *  returns the new tree point.
			 *  If base == 0, then the closest tree point is used */
			virtual Point* extend( Vector2f pt, Point* base = 0) = 0;
			
			/** attempt to connect the tree to the point */
			virtual bool connect(const  Vector2f pt) = 0;
			
			/** make a path from the dest point's root to the dest point
			 *  If rev is true, the path will be from the dest point to its root */
			void addPath(Planning::Path &path, Point* dest, const bool rev = false);
			
			/** returns the first point or 0 if none */
			Point* start() const;
			
			/** last point added */
			Point* last() const;
			
			/** tree step size...interpreted differently for different trees */
			float step;
			
			std::list<Point*> points;
			
		protected:
			const Geometry2d::CompositeShape* _obstacles;
	};
	
	/** tree that grows based on fixed distance step */
	class FixedStepTree : public Tree
	{
		public:
			FixedStepTree() {}
			
			Tree::Point* extend( Vector2f pt, Tree::Point* base = 0);
			bool connect( Vector2f pt);
	};
}

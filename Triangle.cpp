#include "Shape.hpp"
#include "Triangle.hpp"


namespace shapes {
	using easywin::Canvas;

	Triangle::Triangle(int x, int y, int size, COLORREF color)
	{
		Shape::x = x;
		Shape::y = y;
		Shape::size = size;
		Shape::color = color;
	}

	/*-----------------------------------------------TRIANGLE METHODS-------------------------------------------------*/
	std::shared_ptr<Shape> Triangle::clone()
	{
		return std::make_shared<Triangle>(*this);
	}
	void Triangle::draw(easywin::Canvas& canvas)
	{
		std::vector<POINT> triangle = {
			{x,y + size}, //bottom left corner
			{ x + size, y + size }, //bottom right corner
			{ x + size / 2, y} //top middle
		};
		//cursor should be three points 
		canvas.drawPolygon(triangle, 0, color);
	}

	/*A general algorithm to test whether a triangle contains a point can be a little complicated.However,
	we can take advantage of what we know about our triangle(an isosceles triangle whose base is horizontal;
	the height and width are equal) to come up with a simpler algorithm.The y value of your point must be between
	the topand bottom edges of the bounding box, and the slope of the line from your point to the top of the
	triangle must be either ≥ 2, or ≤ - 2. Remember that the slope of a line between two points is
	(p.y - q.y	/ p.x - q.x).Flipping which point is p and which is q just changes the slope from positive to negative,
	which doesn't matter in this case since our slope can be either ≥ 2 or ≤ -2.*/ //WHY IS 2?
	bool Triangle::contains(int x, int y)
	{
		//bounding box values
		int _x = this->x;
		int _y = this->y;

		//top point of the triangle
		POINT p = { _x + size / 2, _y };
		//point user is giving us
		POINT q = { x,y };
		//value of triangle's edge
		double slope;
		if (p.x - q.x == 0) {
			slope = 3;
		}
		else {
			slope = (p.y - q.y) / (p.x - q.x);
		}

		//between the top and the bottom and within the slope
		if (y >= _y && y <= _y + size && (slope >= 2 || slope <= -2)) {
			return true;
		}
		else {
			return false;
		}
	}


}
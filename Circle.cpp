#include "Circle.hpp"
#include "Shape.hpp"
#include <math.h>

namespace shapes {
	using easywin::Canvas;
	/*------------------------------------------------CIRCLE METHODS--------------------------------------------------*/
	double distance(POINT p, POINT q) {

		return sqrt(pow(p.x - q.x, 2) + pow(p.y - q.y, 2));
	}

	Circle::Circle(int x, int y, int size, COLORREF color)
	{
		Shape::x = x;
		Shape::y = y;
		Shape::size = size;
		Shape::color = color;
	}

	std::shared_ptr<Shape> Circle::clone()
	{
		return std::make_shared<Circle>(*this);
	}

	void Circle::draw(easywin::Canvas& canvas)
	{
		unsigned int radius = size / 2;
		POINT center = { this->x + size / 2, this->y + size / 2 };
		canvas.drawEllipse(center, radius, 0, color);
	}

	/*A circle contains a point if the distance from the point to the center of the circle
	is less than the radius.The distance between a point pand a point q is √(p.x - q.x)2 + (p.y - q.y)2.*/
	bool Circle::contains(int x, int y)
	{
		POINT click = { x, y };
		POINT center = { this->x + size / 2, this->y + size / 2 };
		double dist = distance(click, center);  // distance between click and center
		double radius = size / 2;
		if (dist < radius) {
			return true; // we are inside of the circle
		}
		else {
			return false;
		}
	}

}
#include "Shape.hpp"
#include "Square.hpp"

namespace shapes {
	using easywin::Canvas;
	Square::Square(int x, int y, int size, COLORREF color)
	{
		Shape::x = x;
		Shape::y = y;
		Shape::size = size;
		Shape::color = color;
		
	}
	/*------------------------------------------------SQUARE METHODS--------------------------------------------------*/
	std::shared_ptr<Shape> Square::clone()
	{
		return std::make_shared<Square>(*this);
	}
	void Square::draw(easywin::Canvas& canvas)
	{
		canvas.drawRectangle(x, y, x + size, y + size, 0, color);
	}

	/*A square contains a point if the x value of the point is between the left and right edges of the square (inclusive)
	and the y value of the point is between the top and bottom edges of the square (inclusive).*/
	bool Square::contains(int x, int y)
	{
		//x between left and right
		if (x >= this->x && x <= this->x + size && y >= this->y && y <= this->y + size) {
			return true;
		}
		else {
			return false;
		}
	}
}
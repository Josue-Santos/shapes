#include "Shape.hpp"

namespace shapes {
	using easywin::Canvas;
	
	/*--------------------------------------------------SHAPE METHODS--------------------------------------------------*/

	void Shape::moveTo(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Shape::moveBy(int xOffset, int yOffset)
	{
		this->x = x + xOffset;
		this->y = y + yOffset;
	}

	void Shape::resizeBy(int sizeOffset)
	{
		
		size += sizeOffset;
		if (size <= 10) {
			size = 10;
		}
		else if (size >= 500) {
			size = 500;
		}
	
		

	}
}
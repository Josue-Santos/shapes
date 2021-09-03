#pragma once
#include "Shape.hpp"

namespace shapes {
	using easywin::Canvas;
	
	class Square : public Shape {
	public:
		
		Square(int x, int y, int size, COLORREF color);
		std::shared_ptr<Shape> clone() override;
		void draw(easywin::Canvas& canvas) override;
		bool contains(int x, int y) override;
	};

}  // namespace shapes

#pragma once
#include "Shape.hpp"

//here we are going to have the shape base class + all the three derived classes (T, S, C)
namespace shapes {
	using easywin::Canvas;

	class Circle : public Shape {
	public:
		Circle(int x, int y, int size, COLORREF color);
		std::shared_ptr<Shape> clone() override;
		void draw(easywin::Canvas& canvas) override;
		bool contains(int x, int y) override;
	};

}  // namespace shapes

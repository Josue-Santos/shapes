#pragma once
#include "Shape.hpp"

//here we are going to have the shape base class + all the three derived classes (T, S, C)
namespace shapes {
	using easywin::Canvas;

	class Triangle : public Shape {
	public:
		Triangle(int x, int y, int size, COLORREF color);
		std::shared_ptr<Shape> clone() override;
		bool contains(int x, int y) override;
		void draw(easywin::Canvas& canvas) override;
	};

}  // namespace shapes

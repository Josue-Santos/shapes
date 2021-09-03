#pragma once
#include <memory>
#include <map>
#include <string>
#include <random>
#include "Canvas.hpp"
#include "Shape.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

namespace shapes {

	using easywin::Canvas;

	class Shape;

	class ShapeManager {
	public:
		enum class ShapeType { Square, Circle, Triangle };
		const static std::map<ShapeType, std::string> shapeTypes;

		//static - there is only one way to make a shape check the shapetype and create one
		static std::shared_ptr<Shape> makeShape(ShapeType type, int x, int y, int size, COLORREF color);
		void addShape(std::shared_ptr<Shape> shape);
		std::shared_ptr<Shape> select(int x, int y);
		void drawShapes(Canvas& canvas);

	private:
		//vector that holds all the shapes
		std::vector<std::shared_ptr<Shape>> shapes;
	};

}  // namespace shapes
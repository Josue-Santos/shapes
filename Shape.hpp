#pragma once
#include <memory>
#include <map>
#include <string>
#include <random>
#include "Canvas.hpp"
#include "Window.hpp"

//here we are going to have the shape base class + all the three derived classes (T, S, C)
namespace shapes {
	using easywin::Canvas;
	using easywin::Window;

	class Shape {
	protected:
		//bounding box - square: coordinates of its top-left corner and size 
		int x, y, size;
		//color for a kind of shape
		COLORREF color;
		//cursor - struct class that has int x and int y for the coordinates on the window
		//POINT cursor;
		
	public:
		virtual ~Shape() { } 

		//whatever shape you are pointing to I want a copy. make_shared to create a copy
		virtual std::shared_ptr<Shape> clone() = 0;

		//return true when points inside the shape; false otherwise
		virtual bool contains(int x, int y) = 0;

		//move exactly to this point - no bouding checks
		void moveTo(int x, int y); //we can write - just one way to move a shape

		//change your position by certain amount using offsets - no bouding checks
		void moveBy(int xOffset, int yOffset); //just one way to move a shape

		//changing size by a certain amount - bounding check set 10 for the lowest & 500 for the highest
		void resizeBy(int sizeOffset); //only one way to resize

		//using the Canvas.hpp to draw a shape
		virtual void draw(easywin::Canvas& canvas) = 0;

		//defining which ones should be virtual
	};


}  // namespace shapes

#include "ShapeManager.hpp"
#include <stdexcept>
#include <Windows.h>
#include <algorithm>

namespace shapes {

	//map const never will change these values
	const std::map<ShapeManager::ShapeType, std::string> ShapeManager::shapeTypes = {
	  { ShapeManager::ShapeType::Square,   "Square"  },
	  { ShapeManager::ShapeType::Circle,   "Circle"  },
	  { ShapeManager::ShapeType::Triangle, "Triangle"}
	};

	/*This is a factory function which can create an instance of the proper shape class. By providing this factory 
	function, the rest of the program does not need to know any of the specific shape classes being used by this 
	program.*/
	std::shared_ptr<Shape> ShapeManager::makeShape(ShapeType type, int x, int y, int size, COLORREF color)
	{
		if (type == ShapeType::Square) {
			return std::make_shared<Square>(x, y, size, color);
		}
		else if(type == ShapeType::Circle) {
			return std::make_shared<Circle>(x, y, size, color);
		}
		else{
			return std::make_shared<Triangle>(x, y, size, color);
		}
	}

	//This function simply adds a shape to the top of the list of shapes you are managing for the window.
	void ShapeManager::addShape(std::shared_ptr<Shape> shape)
	{
		//adding to the beginning of the shapes vector
		shapes.insert(shapes.begin(),shape);
	}

	/*This function searches the list from top to bottom. The first shape which contains the specified point should be
	selected. This shape should be moved to the top of the list and then returned. If no shapes contain the specified 
	point then return nullptr.*/
	std::shared_ptr<Shape> ShapeManager::select(int x, int y)
	{
		//FIRST: Which shape I am clicking on: I should look for the Top Most Shape that contains the point
		//Loop through a list of my vectors and see if my point is selecting that particular shape
		//SECOND: Whatever shape I am clicking on move it to the Top of the List	
		//then I move that shape to the top
		//If none of the shapes contains the point return nullptr (there is no shape there)
		
		for (int i = 0; i < shapes.size(); i++) {
			if (shapes[i]->contains(x, y)) {
				//we are missing moving it to the top
				std::rotate(shapes.begin(), shapes.begin()+i, shapes.end());
				return shapes[0];
			}	
		}
		return nullptr;
	}

	//Draw the shapes to the canvas from bottom to top.
	void ShapeManager::drawShapes(Canvas& canvas)
	{
		//draw the shapes just calling it each shape from particular shape we want, this must be Bottom to Top
		//Check the vector list and starting drawing from bottom to top
		int bottom = shapes.size()-1;
		for (int i = bottom; i >= 0; i--)
		{
			shapes[i]->draw(canvas);
		}
	
	}

}  // namespace shapes
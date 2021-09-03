#pragma once
#undef UNICODE
#include <windows.h>
#include <string>
#include <vector>

namespace easywin {

	class Canvas {
		HDC hdc;

	public:
		Canvas(HDC hdc);

		//user give the positions I can make a square from this
		void drawRectangle(int left, int top, int right, int bottom,
			COLORREF lineColor, COLORREF fillColor);
		//I can make a circle from this
		void drawEllipse(POINT center, unsigned int radius,
			COLORREF lineColor, COLORREF fillColor);
		//I can make a Triangle from this, just give it three points
		void drawPolygon(const std::vector<POINT>& points,
			COLORREF lineColor, COLORREF fillColor);
		//not necessary for the project
		void drawText(POINT topLeft, const std::string& text,
			COLORREF textColor, COLORREF fillColor);
	};

}  // namespace easywin


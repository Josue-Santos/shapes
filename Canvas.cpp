#define _WIN32_WINNT 0x500
#include "Canvas.hpp"
#include <stdexcept>

namespace easywin {

	Canvas::Canvas(HDC hdc) : hdc(hdc) {
	}

	void Canvas::drawRectangle(int left, int top, int right, int bottom,
		COLORREF lineColor, COLORREF fillColor) {
		if (hdc == 0) {
			throw std::logic_error("Only call drawRectangle from the Paint method");
		}
		SetDCPenColor(hdc, lineColor);
		SetDCBrushColor(hdc, fillColor);
		Rectangle(hdc, left, top, right + 1, bottom + 1);
	}

	void Canvas::drawEllipse(POINT center, unsigned int radius,
		COLORREF lineColor, COLORREF fillColor) {
		if (hdc == 0) {
			throw std::logic_error("Only call drawEllipse from the Paint method");
		}
		SetDCPenColor(hdc, lineColor);
		SetDCBrushColor(hdc, fillColor);
		Ellipse(
			hdc,
			center.x - radius,
			center.y - radius,
			center.x + radius + 1,
			center.y + radius + 1
		);
	}

	void Canvas::drawPolygon(const std::vector<POINT>& points, COLORREF lineColor,
		COLORREF fillColor) {
		if (hdc == 0) {
			throw std::logic_error("Only call drawPolygon from the Paint method");
		}
		SetDCPenColor(hdc, lineColor);
		SetDCBrushColor(hdc, fillColor);
		Polygon(hdc, points.data(), points.size());
	}

	void Canvas::drawText(POINT topLeft, const std::string& text,
		COLORREF textColor, COLORREF fillColor) {
		if (hdc == 0) {
			throw std::logic_error("Only call drawText from the Paint method");
		}
		SetBkColor(hdc, fillColor);
		TextOut(hdc, topLeft.x, topLeft.y, text.data(), text.size());
	}

}  // namespace shapes
#include "stdafx.h"
#include "DrawPolygons.h"

namespace DrawPolygons {

	void DrawPolygon(float sx, float sy, float size, int corners, float angle, float r, float g, float b) {
		// Vertices of 1st corner
		float vstart_x{ sx }, vstart_y{ sy };
		float vend_x{}, vend_y{};

		// Draw corners
		for (int i{ 0 }; i < corners; i++) {
			vend_x = FindNextVertexX(vstart_x, size, angle + i * 360 / corners);
			vend_y = FindNextVertexY(vstart_y, size, angle + i * 360 / corners);
			App::DrawLine(vstart_x, vstart_y, vend_x, vend_y, r, g, b);

			vstart_x = vend_x;
			vstart_y = vend_y;
		}
	}

	float FindNextVertexX(float xcoord, float size, float angle) {
		return (size * cosf(angle * PI / 180) + xcoord);
	}

	float FindNextVertexY(float ycoord, float size, float angle) {
		return (size * sinf(angle * PI / 180) + ycoord);
	}

	void DrawSquareLevel(float sx, float sy, float size, float scale, float angle, float r, float g, float b) {
		float innerOffset{ 3 * size / 8 };
		DrawPolygon(sx, sy, size, 4, angle, r, g, b);
		DrawPolygon(sx + innerOffset, sy + innerOffset, size * scale, 4, angle, r, g, b);
	}
}
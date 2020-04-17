#include "stdafx.h"
#include "DrawPolygons.h"

namespace DrawPolygons {

	std::vector<std::pair<float, float>> DrawPolygon(float sx, float sy, float size, int corners, float angle, float r, float g, float b) {
		// Vertices of 1st corner
		float vstart_x{ sx }, vstart_y{ sy };
		float vend_x{}, vend_y{};

		// stored vertices
		std::pair<float, float> vertex;
		std::vector<std::pair<float, float>> vertices;

		// Draw corners
		for (int i{ 0 }; i < corners; i++) {
			for (int j{ 0 }; j < corners; j++) {
				vend_x = FindNextVertexX(vstart_x, size/corners, angle + i * 360 / corners);
				vend_y = FindNextVertexY(vstart_y, size/corners, angle + i * 360 / corners);
				vertex.first = vstart_x;
				vertex.second = vstart_y;
				vertices.push_back(vertex);
			
				ShipSlot ship{ vstart_x, vstart_y, vend_x, vend_y, size / corners };
				//App::DrawLine(vstart_x, vstart_y, vend_x, vend_y, r, g, b);

				vstart_x = vend_x;
				vstart_y = vend_y;
			}
		}

		return vertices;
	}

	float FindNextVertexX(float xcoord, float size, float angle) {
		return (size * cosf(angle * PI / 180) + xcoord);
	}

	float FindNextVertexY(float ycoord, float size, float angle) {
		return (size * sinf(angle * PI / 180) + ycoord);
	}

	void DrawSquareLevel(float sx, float sy, float size, float scale, float angle, float r, float g, float b) {
		float innerOffset{ 3 * size / 8 };
		auto outerVertices{ DrawPolygon(sx, sy, size, 4, angle, r, g, b) };
		auto innerVertices{ DrawPolygon(sx + innerOffset, sy + innerOffset, size * scale, 4, angle, r, g, b) };

		for (auto i{ 0 }; i < outerVertices.size(); i++) {
			App::DrawLine(outerVertices.at(i).first, outerVertices.at(i).second, innerVertices.at(i).first, innerVertices.at(i).second, r, g, b);
		}
	}
}
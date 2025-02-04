#include "stdafx.h"
#include "PolygonUtil.h"

namespace PolygonUtil {

	std::vector<std::pair<float, float>> PolygonCoordinates(float sx, float sy, float size, int corners, float angle) {
		// Coordinates of the 1st slot
		float vstart_x{ sx }, vstart_y{ sy };
		float vend_x{}, vend_y{};

		// Stored vertices
		std::pair<float, float> vertex;
		std::vector<std::pair<float, float>> vertices;

		// Draw corners
		for (int i{ 0 }; i < corners; i++) {
			for (int j{ 0 }; j < corners; j++) {
				vend_x = FindNextVertexX(vstart_x, size/corners, angle + i * 360 / corners);
				vend_y = FindNextVertexY(vstart_y, size/corners, angle + i * 360 / corners);

				vertex.first = vstart_x;
				vertex.second = vstart_y;
				vertices.emplace_back(vertex);

				vstart_x = vend_x;
				vstart_y = vend_y;
			}
		}
		vertex.first = vstart_x;
		vertex.second = vstart_y;
		vertices.emplace_back(vertex);

		return vertices;
	}

	float FindNextVertexX(float xcoord, float size, float angle) {
		return (size * cosf(angle * PI / 180) + xcoord);
	}

	float FindNextVertexY(float ycoord, float size, float angle) {
		return (size * sinf(angle * PI / 180) + ycoord);
	}

	void ConnectPolygons(std::vector<std::pair<float, float>> outerShape, std::vector<std::pair<float, float>> innerShape) {
		if (outerShape.size() != innerShape.size()) {
			return;
		}

		for (size_t i{ 0 }; i < outerShape.size(); i++) {
			App::DrawLine(outerShape.at(i).first, outerShape.at(i).second, innerShape.at(i).first, innerShape.at(i).second);
		}
	}

	void PopulateShipVector(std::vector<LineSlot>& shipVec, const std::vector<std::pair<float, float>>& coordinates, float size, int corners) {
		for (size_t i{ 1 }; i < coordinates.size() ; i++) {
			shipVec.emplace_back(coordinates.at(i - 1).first, coordinates.at(i - 1).second, coordinates.at(i).first, coordinates.at(i).second, size / corners);
		}
	}

	void PopulateShipVector(std::vector<LineSlot>& shipVec, const std::vector<std::pair<float, float>>& coordinates, float size, int corners, std::vector<LineSlot>::iterator& it) {
		PopulateShipVector(shipVec, coordinates, size, corners);
		it = shipVec.begin();
	}
}
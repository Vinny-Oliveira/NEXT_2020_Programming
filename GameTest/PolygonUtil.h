#ifndef _POLYGON_UTIL_H_
#define _POLYGON_UTIL_H_

#include <math.h>
#include <vector>
#include "App/app.h"
#include "ShipSlot.h"

namespace PolygonUtil {

	//-------------------------------------------------------------------------------------------
	// Draw a polygon with a vertex on (sx, sy), side length size, a number of corners, base angle in degrees, and colors r,g,b
	//-------------------------------------------------------------------------------------------
	std::vector<std::pair<float, float>> PolygonCoordinates(float sx, float sy, float size, int corners, float angle = 0.0f);
	
	//-------------------------------------------------------------------------------------------
	// When drawing the side of a 2D shape of side length size, find the x coordinate of the next vertex
	//-------------------------------------------------------------------------------------------
	float FindNextVertexX(float xcoord, float size, float angle = 0.0f);
	
	//-------------------------------------------------------------------------------------------
	// When drawing the side of a 2D shape of side length size, find the y coordinate of the next vertex
	//-------------------------------------------------------------------------------------------
	float FindNextVertexY(float ycoord, float size, float angle = 0.0f);

	//-------------------------------------------------------------------------------------------
	// Draw connecting lines between inner and outer polygons
	//-------------------------------------------------------------------------------------------
	void ConnectPolygons(std::vector<std::pair<float, float>> outerShape, std::vector<std::pair<float, float>> innerShape);

	//-------------------------------------------------------------------------------------------
	// Populate a vector of ship slots with the proper coordinates
	//-------------------------------------------------------------------------------------------
	void PopulateShipVector(std::vector<ShipSlot>& shipVec, const std::vector<std::pair<float, float>>& coordinates, float size, int corners);
	void PopulateShipVector(std::vector<ShipSlot>& shipVec, const std::vector<std::pair<float, float>>& coordinates, float size, int corners, std::vector<ShipSlot>::iterator& it);
}

#endif // !_POLYGON_UTIL_H_

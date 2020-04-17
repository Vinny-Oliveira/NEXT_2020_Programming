#ifndef _DRAW_SHAPES_H_
#define _DRAW_POLYGONS_H_

#include <math.h>
#include "App/app.h"

namespace DrawPolygons {

	//-------------------------------------------------------------------------------------------
	// Draw a polygon with a vertex on (sx, sy), side length size, a number of corners, base angle in degrees, and colors r,g,b
	//-------------------------------------------------------------------------------------------
	void DrawPolygon(float sx, float sy, float size, int corners, float angle = 0.0f, float r = 1.0f, float g = 1.0f, float b = 1.0f);
	
	//-------------------------------------------------------------------------------------------
	// When drawing the side of a 2D shape of side length size, find the x coordinate of the next vertex
	//-------------------------------------------------------------------------------------------
	float FindNextVertexX(float xcoord, float size, float angle = 0.0f);
	
	//-------------------------------------------------------------------------------------------
	// When drawing the side of a 2D shape of side length size, find the y coordinate of the next vertex
	//-------------------------------------------------------------------------------------------
	float FindNextVertexY(float ycoord, float size, float angle = 0.0f);


	void DrawSquareLevel(float sx, float sy, float size, float scale, float angle = 0.0f, float r = 1.0f, float g = 1.0f, float b = 1.0f);
}

#endif // !_DRAW_POLYGONS_H_

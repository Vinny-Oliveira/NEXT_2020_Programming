#include "stdafx.h"
#include "LineSlot.h"

LineSlot::LineSlot()
	: LineSlot{ 0, 0, 0, 0, 0 } {

}

LineSlot::LineSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle, int hp)
	: xCoordLeft{ xStart }, 
	  yCoordLeft{ yStart }, 
	  xCoordRight{ xEnd }, 
	  yCoordRight{ yEnd },
	  xCoordCenter{ (xCoordLeft + xCoordRight) / 2 },
	  yCoordCenter{ (yCoordLeft + yCoordRight) / 2 },
	  health{ hp },
	  isAlive{ true } {
	
}

void LineSlot::DrawSlot() { 
	float g{};
	float b{};
	if (isAlive) {
		g = 1;
		b = 1;
	}
	App::DrawLine(xCoordLeft, yCoordLeft, xCoordRight, yCoordRight, 1, g, b); 
}
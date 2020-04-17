#include "stdafx.h"
#include "ShipSlot.h"

ShipSlot::ShipSlot()
	: ShipSlot{ 0, 0, 0, 0, 0 } {

}

ShipSlot::ShipSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle)
	: xCoordLeft{ xStart }, 
	  yCoordLeft{ yStart }, 
	  xCoordRight{ xEnd }, 
	  yCoordRight{ yEnd },
	  xCoordCenter{ (xCoordLeft + xCoordRight) / 2 },
	  yCoordCenter{ (yCoordLeft + yCoordRight) / 2 } {
	App::DrawLine(xCoordLeft, yCoordLeft, xCoordRight, yCoordRight);
}


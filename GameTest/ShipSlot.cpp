#include "stdafx.h"
#include "ShipSlot.h"

ShipSlot::ShipSlot()
	: ShipSlot{ 0, 0, 0, 0, 0 } {

}

ShipSlot::ShipSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle)
	: LineSlot{ xStart, yStart, xEnd, yEnd, size, angle } {

}
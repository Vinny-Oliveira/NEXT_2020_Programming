#ifndef _SHIP_SLOT_H_
#define _SHIP_SLOT_H_

#include <iostream>
#include "App/app.h"

class ShipSlot {
private:
	float xCoordLeft,	yCoordLeft;
	float xCoordRight,	yCoordRight;
	float xCoordCenter,	yCoordCenter;

public:
	ShipSlot();
	ShipSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f);
	//ShipSlot(const ShipSlot& source); // Copy constructor
	//ShipSlot(ShipSlot&& source);
	~ShipSlot() = default;

	float GetCenterX() { return xCoordCenter; }
	float GetCenterY() { return yCoordCenter; }

	void DrawSlot() { App::DrawLine(xCoordLeft, yCoordLeft, xCoordRight, yCoordRight, 1, 1, 1); }
};

#endif // !_SHIP_SLOT_H_

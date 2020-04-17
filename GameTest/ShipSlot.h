#ifndef _SHIP_SLOT_H_
#define _SHIP_SLOT_H_

#include "App/app.h"

class ShipSlot {
private:
	float xCoordLeft,	yCoordLeft;
	float xCoordRight,	yCoordRight;
	float xCoordCenter,	yCoordCenter;

public:
	ShipSlot();
	ShipSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f);
	~ShipSlot() = default;


};

#endif // !_SHIP_SLOT_H_

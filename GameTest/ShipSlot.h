#ifndef _SHIP_SLOT_H_
#define _SHIP_SLOT_H_

#include "LineSlot.h"

class ShipSlot : public LineSlot {
private:


public:
	ShipSlot();
	ShipSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f);
	~ShipSlot() = default;

};

#endif // !_SHIP_SLOT_H_

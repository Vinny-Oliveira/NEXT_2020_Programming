#ifndef _LINE_SLOT_H_
#define _LINE_SLOT_H_

#include <iostream>
#include "App/app.h"

class LineSlot {
private:
	float xCoordLeft{};		float yCoordLeft{};
	float xCoordRight{};	float yCoordRight{};
	float xCoordCenter{};	float yCoordCenter{};

	bool isAlive{};

public:
	LineSlot();
	LineSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f);
	~LineSlot() = default;

	float GetCenterX() { return xCoordCenter; }
	float GetCenterY() { return yCoordCenter; }

	bool IsAlive() { return isAlive; }
	void SetSlotDead() { isAlive = false; }

	// Draw the line white if it is alive, red if it is not
	void DrawSlot();
};

#endif // !_LINE_SLOT_H_

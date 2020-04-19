#ifndef _LINE_SLOT_H_
#define _LINE_SLOT_H_

#include <iostream>
#include "App/app.h"

class LineSlot {
private:
	float xCoordLeft{};		float yCoordLeft{};
	float xCoordRight{};	float yCoordRight{};
	float xCoordCenter{};	float yCoordCenter{};

public:
	LineSlot();
	LineSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f);
	~LineSlot() = default;

	float GetCenterX() { return xCoordCenter; }
	float GetCenterY() { return yCoordCenter; }

	void DrawSlot() { App::DrawLine(xCoordLeft, yCoordLeft, xCoordRight, yCoordRight, 1, 1, 1); }
};

#endif // !_LINE_SLOT_H_

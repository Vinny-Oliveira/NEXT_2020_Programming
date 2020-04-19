#ifndef _LINE_SLOT_H_
#define _LINE_SLOT_H_

#include <iostream>
#include "App/app.h"

class LineSlot {
private:
	float xCoordLeft{};		float yCoordLeft{};
	float xCoordRight{};	float yCoordRight{};
	float xCoordCenter{};	float yCoordCenter{};

	int health{};
	bool isAlive{};
	
	static constexpr int def_health = 5;

public:
	LineSlot();
	LineSlot(float xStart, float yStart, float xEnd, float yEnd, float size, float angle = 0.0f, int hp = def_health);
	~LineSlot() = default;

	float GetCenterX() { return xCoordCenter; }
	float GetCenterY() { return yCoordCenter; }

	void DrawSlot() { App::DrawLine(xCoordLeft, yCoordLeft, xCoordRight, yCoordRight, 1, 1, 1); }
};

#endif // !_LINE_SLOT_H_

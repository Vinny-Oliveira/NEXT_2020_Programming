#ifndef _BULLET_H_
#define _BULLET_H_

#include "App/app.h"

class Bullet {
private:
	CSimpleSprite* bulletSprite;

	bool launched{};
	bool collided{};
	float speed{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};


public:
	Bullet() = default;
	~Bullet() = default;

	CSimpleSprite* GetSprite() { return bulletSprite; }
	void SetSprite(CSimpleSprite* sprite) { bulletSprite = sprite; }
	void SetSpeed(float newSpeed) { speed = newSpeed; }
	void SetTarget(float x, float y) { xTarget = x; yTarget = y; }
};

#endif // !_BULLET_H_

#ifndef _BULLET_H_
#define _BULLET_H_

#include "App/app.h"
#include "LineSlot.h"
#include "ShipPositioning.h"

class Bullet {
private:
	CSimpleSprite* bulletSprite{ nullptr };
	LineSlot target;

	bool launched{};
	bool collided{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};
	float slope{};

public:
	Bullet();
	Bullet(CSimpleSprite sprite);
	Bullet(const Bullet& source);
	Bullet(Bullet&& source) noexcept;
	~Bullet();

	CSimpleSprite* GetSprite() { return bulletSprite; }
	void SetSprite(CSimpleSprite* sprite) { bulletSprite = sprite; }
	//void SetSpeed(float newSpeed) { speed = newSpeed; }
	//void SetTarget(float x, float y) { xTarget = x; yTarget = y; }
	
	bool GetLaunched() { return launched; }
	void SetLaunched(bool isLaunch) { launched = isLaunch; }

	void LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index);
	void GoToTarget();
};

#endif // !_BULLET_H_

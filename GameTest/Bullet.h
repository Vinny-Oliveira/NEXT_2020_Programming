#ifndef _BULLET_H_
#define _BULLET_H_

#include "App/app.h"

class Bullet {
private:
	CSimpleSprite* bulletSprite{ nullptr };

	bool launched{};
	bool collided{};
	float speed{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};


public:
	Bullet();
	Bullet(CSimpleSprite sprite);
	Bullet(const Bullet& source);
	Bullet(Bullet&& source) noexcept;
	~Bullet();

	CSimpleSprite* GetSprite() { return bulletSprite; }
	void SetSprite(CSimpleSprite* sprite) { bulletSprite = sprite; }
	void SetSpeed(float newSpeed) { speed = newSpeed; }
	void SetTarget(float x, float y) { xTarget = x; yTarget = y; }
	
	bool GetLaunched() { return launched; }
	void SetLaunched(bool isLaunch) { launched = isLaunch; }

	void LaunchBullet();
};

#endif // !_BULLET_H_

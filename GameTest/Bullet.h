#ifndef _BULLET_H_
#define _BULLET_H_

#include <memory>
#include <math.h>
#include <cmath>
#include "App/app.h"
#include "LineSlot.h"

class Bullet {
private:
	CSimpleSprite* bulletSprite{ nullptr };
	CSimpleSprite* shipSprite{ nullptr };
	LineSlot* target{ nullptr };

	//std::shared_ptr<CSimpleSprite> bulletSprite{ nullptr };
	//std::shared_ptr<LineSlot> target{ nullptr };

	bool isLaunched{};
	bool collided{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};
	float slope{};

public:
	Bullet();
	Bullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot);
	Bullet(const Bullet& source);
	Bullet(Bullet&& source) noexcept;
	~Bullet();

	auto GetBullet() { return bulletSprite; }
	void SetBullet(CSimpleSprite* sprite) { bulletSprite = sprite; }
	
	auto GetShip() { return shipSprite; }
	void SetShip(CSimpleSprite* sprite) { shipSprite = sprite; }
	//void SetSprite(CSimpleSprite* sprite) { bulletSprite = std::make_shared<CSimpleSprite>(*sprite); }
	
	bool GetLaunched() { return isLaunched; }
	void SetLaunched(bool isLaunch) { isLaunched = isLaunch; }

	void CreateSprite();
	
	// Launch a bullet towards its target
	void LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index);
	
	// Make the bullet travel to its target following a line
	bool GoToTarget(int& counter);

	// Match the bullet's position and rotation to those of the ship
	void MatchShipPosition();
};

#endif // !_BULLET_H_

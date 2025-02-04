#ifndef _BULLET_H_
#define _BULLET_H_

#include <math.h>
#include <cmath>
#include "App/app.h"
#include "LineSlot.h"

class Bullet {
private:
	CSimpleSprite* shipSprite{ nullptr };

protected:
	CSimpleSprite* bulletSprite{ nullptr };
	LineSlot* target{ nullptr };

	bool isLaunched{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};
	float slope{};

public:
	Bullet();
	Bullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot);
	Bullet(const Bullet& source);
	Bullet(Bullet&& source) noexcept;
	virtual ~Bullet();

	auto GetBullet() { return bulletSprite; }
	void SetBullet(CSimpleSprite* sprite) { bulletSprite = sprite; }
	
	auto GetShip() { return shipSprite; }
	void SetShip(CSimpleSprite* sprite) { shipSprite = sprite; }
	
	bool GetLaunched() { return isLaunched; }
	void SetLaunched(bool isLaunch) { isLaunched = isLaunch; }

	// Create a bullet sprite
	void CreateSprite(int frame);
	
	// Launch a bullet towards its target
	void LaunchBullet(LineSlot& new_target);
	
	// Make the bullet travel to its target following a line
	bool GoToTarget();

	// Match the bullet's position and rotation to those of the ship
	void MatchShipPosition();
	
	// Define the bullet's target position
	void DefineTarget(LineSlot& new_target);

	// Calculate the slope between the target and the starting position
	void CalculateSlope();
};

#endif // !_BULLET_H_

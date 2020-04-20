#ifndef _ENEMY_BULLET_H_
#define _ENEMY_BULLET_H_

#include "Bullet.h"

class EnemyBullet : public Bullet {
private:
	// Static variable to determine if the bullets may be shot
	static bool canShoot;

public:
	EnemyBullet();
	EnemyBullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot);
	EnemyBullet(const EnemyBullet& source);
	EnemyBullet(EnemyBullet&& source) noexcept;
	virtual ~EnemyBullet() = default;

	bool GetCanShoot() { return canShoot; }
	void SetCanShoot(bool shoot) { canShoot = shoot; }

	// Launch a bullet from an enemy slot to a target
	void LaunchBullet(LineSlot& startSlot, LineSlot& new_target);

	// Match the bullet's position and rotation to those of the ship
	void GoToStartingPosition(LineSlot& slot);
};

#endif // !_ENEMY_BULLET_H_

#ifndef _ENEMY_BULLET_H_
#define _ENEMY_BULLET_H_

#include "Bullet.h"

class EnemyBullet : public Bullet {
private:
	static bool canShoot;

public:
	EnemyBullet();
	EnemyBullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot);
	EnemyBullet(const EnemyBullet& source);
	EnemyBullet(EnemyBullet&& source) noexcept;
	virtual ~EnemyBullet() = default;

	virtual void LaunchBullet(std::vector<LineSlot>& targets, int index) override;
};

#endif // !_ENEMY_BULLET_H_

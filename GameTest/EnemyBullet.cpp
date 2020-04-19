#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
	: Bullet{} {

}

EnemyBullet::EnemyBullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot)
	: Bullet{ bullet, ship, lineSlot } {

}

EnemyBullet::EnemyBullet(const EnemyBullet& source)
	: Bullet{ source } {

}

EnemyBullet::EnemyBullet(EnemyBullet&& source) noexcept {
	bulletSprite = source.bulletSprite;
	//shipSprite = source.shipSprite;
	target = source.target;
	source.bulletSprite = nullptr;
	//source.shipSprite = nullptr;
	source.target = nullptr;
}

bool EnemyBullet::canShoot = true;

void EnemyBullet::LaunchBullet(std::vector<LineSlot>& targets, int index) {
	if (canShoot) {
		Bullet::LaunchBullet(targets, index);
	}
}
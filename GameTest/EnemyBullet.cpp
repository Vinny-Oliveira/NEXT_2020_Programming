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

EnemyBullet::EnemyBullet(EnemyBullet&& source) noexcept
	: Bullet{ source } {

}

void EnemyBullet::LaunchBullet(std::vector<LineSlot>& targets, int index) {
	if (!isWaiting) {
		Bullet::LaunchBullet(targets, index);
	}
}
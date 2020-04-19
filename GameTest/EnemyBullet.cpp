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

void EnemyBullet::LaunchBullet(LineSlot& startSlot, LineSlot& new_target) {
	DefineTarget(new_target);
	GoToStartingPosition(startSlot);
	CalculateSlope();
	isLaunched = true;
}

void EnemyBullet::GoToStartingPosition(LineSlot& slot) {
	xPos = slot.GetCenterX();
	yPos = slot.GetCenterY();
	bulletSprite->SetPosition(xPos, yPos);
	
	float dy = yTarget - yPos;
	float dx = xTarget - xPos;
	bulletSprite->SetAngle(atan2f(dy, dx) - PI / 2);
}
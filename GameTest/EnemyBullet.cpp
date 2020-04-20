#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet()
	: Bullet{} {

}

EnemyBullet::EnemyBullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot)
	: Bullet{ bullet, ship, lineSlot } {

}

// Copy constructor
EnemyBullet::EnemyBullet(const EnemyBullet& source)
	: Bullet{ source } {

}

// Move constructor
EnemyBullet::EnemyBullet(EnemyBullet&& source) noexcept {
	bulletSprite = source.bulletSprite;
	target = source.target;
	source.bulletSprite = nullptr;
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
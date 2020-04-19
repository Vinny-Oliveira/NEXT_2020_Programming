#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
	: bulletSprite{ nullptr } {
}

Bullet::Bullet(CSimpleSprite sprite) {
	*bulletSprite = sprite;
}

Bullet::Bullet(const Bullet& source)
	: Bullet{ *(source.bulletSprite) } {

}

Bullet::Bullet(Bullet&& source) noexcept
	: bulletSprite{ source.bulletSprite } {
	source.bulletSprite = nullptr;
}

Bullet::~Bullet() {
	delete bulletSprite;
}

void Bullet::LaunchBullet() {

}
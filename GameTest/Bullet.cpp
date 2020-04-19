#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
	: bulletSprite{ nullptr } {
}

Bullet::Bullet(CSimpleSprite sprite) {
	*bulletSprite = sprite;
}

// Copy constructor
Bullet::Bullet(const Bullet& source)
	: Bullet{ *(source.bulletSprite) } {

}

// Move constructor
Bullet::Bullet(Bullet&& source) noexcept
	: bulletSprite{ source.bulletSprite } {
	source.bulletSprite = nullptr;
}

Bullet::~Bullet() {
	delete bulletSprite;
}

// Launch a bullet from the ship and set its target
void Bullet::LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index) {
	launched = true;
	xPos = ship_it->GetCenterX();
	yPos = ship_it->GetCenterY();

	target = targets.at(index);
	xTarget = target.GetCenterX();
	yTarget = target.GetCenterY();

	if (xPos == xTarget) {
		slope = NAN;
	} else {
		slope = (yTarget - yPos) / (xTarget - xPos);
	}
}

// Make the bullet travel to its target following a line
void Bullet::GoToTarget() {
	if (xPos < xTarget) {
		xPos++;
	} else if (xPos > xTarget) {
		xPos--;
	}

	if (slope == NAN) {
		if (yPos < yTarget) {
			yPos++;
		} else if (yPos > yTarget) {
			yPos--;
		}
	} else if (yPos != yTarget) {
		yPos = slope * (xPos - xTarget) + yTarget; // Line equation
	}

	bulletSprite->SetPosition(xPos, yPos);
}
#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
	: bulletSprite{ nullptr }, target{ nullptr } {
}

Bullet::Bullet(CSimpleSprite sprite, LineSlot lineSlot) {
	bulletSprite = &sprite;
	target = &lineSlot;
}

// Copy constructor
Bullet::Bullet(const Bullet& source)
	: Bullet{ *(source.bulletSprite), *(source.target) } {

}

// Move constructor
Bullet::Bullet(Bullet&& source) noexcept
	: bulletSprite{ source.bulletSprite }, target{ source.target } {
	source.bulletSprite = nullptr;
	source.target = nullptr;
}

Bullet::~Bullet() {
	delete bulletSprite;
	//delete target;
}

// Launch a bullet from the ship and set its target
void Bullet::LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index) {
	launched = true;
	xPos = ship_it->GetCenterX();
	yPos = ship_it->GetCenterY();

	target = &(targets.at(index));
	xTarget = target->GetCenterX();
	yTarget = target->GetCenterY();

	if (xPos == xTarget) {
		slope = NAN;
	} else {
		slope = (yTarget - yPos) / (xTarget - xPos);
	}
}

bool Bullet::GoToTarget(int& counter) {
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

	if ((fabsf(xPos - xTarget) < 2) && (fabsf(yPos - yTarget) < 2)) {
		if (target->IsAlive()) {
			target->SetSlotDead();
			counter++;
		}
		launched = false;
		return true;
	}

	return false;
}
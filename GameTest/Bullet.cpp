#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
	: bulletSprite{ nullptr }, shipSprite{ nullptr }, target{ nullptr } {
}

Bullet::Bullet(CSimpleSprite bullet, CSimpleSprite ship, LineSlot lineSlot) 
	: bulletSprite{ &bullet }, shipSprite{ &ship }, target{ &lineSlot } {
}

// Copy constructor
Bullet::Bullet(const Bullet& source)
	: Bullet{ *(source.bulletSprite), *(source.shipSprite), *(source.target) } {

}

// Move constructor
Bullet::Bullet(Bullet&& source) noexcept
	: bulletSprite{ source.bulletSprite }, shipSprite { source.shipSprite }, target{ source.target } {
	source.bulletSprite = nullptr;
	source.shipSprite = nullptr;
	source.target = nullptr;
}

Bullet::~Bullet() {
	shipSprite = nullptr;
	bulletSprite = nullptr;
	target = nullptr;
	delete shipSprite;
	delete bulletSprite;
	delete target;
}

// Launch a bullet from the ship and set its target
void Bullet::LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index) {
	MatchShipPosition();
	isLaunched = true;

	target = &(targets.at(index));
	xTarget = target->GetCenterX();
	yTarget = target->GetCenterY();

	if (fabsf(xTarget - xPos) < 0.0001f) {
		slope = NAN;
	} else {
		slope = (yTarget - yPos) / (xTarget - xPos);
	}
}

// Make the bullet travel to its target following a line
bool Bullet::GoToTarget(int& counter) {
	// Move x
	if (xPos < xTarget) {
		xPos++;
	} else if (xPos > xTarget) {
		xPos--;
	}

	// Calculate linear equation to move y
	if (std::isnan(slope)) {
		if (yPos < yTarget) {
			yPos++;
		} else if (yPos > yTarget) {
			yPos--;
		}
	} else if (yPos != yTarget) {
		yPos = slope * (xPos - xTarget) + yTarget; // Linear equation
	}

	bulletSprite->SetPosition(xPos, yPos);

	// Kill the target
	if ((fabsf(xPos - xTarget) < 2) && (fabsf(yPos - yTarget) < 2)) {
		if (target->IsAlive()) {
			target->SetSlotDead();
			counter++;
		}
		isLaunched = false;
		MatchShipPosition();
		return true;
	}

	return false;
}

void Bullet::MatchShipPosition() {
	if (!isLaunched) {
		shipSprite->GetPosition(xPos, yPos);
		bulletSprite->SetPosition(xPos, yPos);
		bulletSprite->SetAngle(shipSprite->GetAngle());
	}
}

void Bullet::CreateSprite() {
	bulletSprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	bulletSprite->SetFrame(5);
	bulletSprite->SetScale(0.8f);
}
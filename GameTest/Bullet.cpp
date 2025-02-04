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

void Bullet::CreateSprite(int frame) {
	bulletSprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	bulletSprite->SetFrame(frame);
	bulletSprite->SetScale(0.8f);
}

void Bullet::LaunchBullet(LineSlot& new_target) {
	isLaunched = true;
	MatchShipPosition();
	DefineTarget(new_target);
	CalculateSlope();
}

// Make the bullet travel to its target following a line
bool Bullet::GoToTarget() {
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
		}
		isLaunched = false;
		return true;
	}

	return false;
}

void Bullet::MatchShipPosition() {
	shipSprite->GetPosition(xPos, yPos);
	bulletSprite->SetPosition(xPos, yPos);
	bulletSprite->SetAngle(shipSprite->GetAngle());
}

void Bullet::DefineTarget(LineSlot& new_target) {
	target = &new_target;
	xTarget = target->GetCenterX();
	yTarget = target->GetCenterY();
}

void Bullet::CalculateSlope() {
	if (fabsf(xTarget - xPos) < 0.0001f) {
		slope = NAN;
	} else {
		slope = (yTarget - yPos) / (xTarget - xPos);
	}
}
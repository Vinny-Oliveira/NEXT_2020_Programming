#include "stdafx.h"
#include "ShipPositioning.h"

void MoveUp(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaUp);
}

void MoveDown(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaDown);
}

void MoveLeft(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaLeft);
}

void MoveRight(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaRight);
}

template<typename F>
void MoveShip(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite, F lambdaMove) {
	auto it_around{ it };

	// First, check the previous slot
	CheckPreviousSlot(it_around, shipSlots);
	if (CanMove(it, it_around, shipSprite, lambdaMove(it, it_around))) {
		return;
	}

	// Check the next slot
	it_around = it;
	CheckNextSlot(it_around, shipSlots);
	CanMove(it, it_around, shipSprite, lambdaMove(it, it_around));
}

void CheckPreviousSlot(std::vector<ShipSlot>::iterator& it_around, std::vector<ShipSlot>& shipSlots) {
	if (it_around == shipSlots.begin()) {
		it_around = shipSlots.end();
	}
	it_around--;
}

void CheckNextSlot(std::vector<ShipSlot>::iterator& it_around, std::vector<ShipSlot>& shipSlots) {
	it_around++;
	if (it_around == shipSlots.end()) {
		it_around = shipSlots.begin();
	}
}

bool CanMove(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around, CSimpleSprite* shipSprite, bool canMove) {
	if (canMove) {
		SetSpritePosition(it, it_around, shipSprite);
		return true;
	}

	return false;
}

void SetSpritePosition(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around, CSimpleSprite* shipSprite) {
	it = it_around;
	shipSprite->SetPosition(it->GetCenterX(), it->GetCenterY());
}

void SetSpriteAngle(const std::vector<ShipSlot>& vecShips, std::vector<ShipSlot>& vecTargets, std::vector<ShipSlot>::iterator& it, CSimpleSprite* shipSprite) {
	int enemyIndex = it - vecShips.begin();
	float dy = vecTargets.at(enemyIndex).GetCenterY() - it->GetCenterY();
	float dx = vecTargets.at(enemyIndex).GetCenterX() - it->GetCenterX();
	shipSprite->SetAngle(atan2f(dy, dx) - PI/2);
}

void SpritePositionMatch(Bullet& bullet, CSimpleSprite* spriteToMatch) {
	if (bullet.GetLaunched()) {
		return;
	}
	float x, y;
	spriteToMatch->GetPosition(x, y);
	bullet.GetSprite()->SetPosition(x, y);
	bullet.GetSprite()->SetAngle(spriteToMatch->GetAngle());
}
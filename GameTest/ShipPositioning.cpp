#include "stdafx.h"
#include "ShipPositioning.h"

void MoveUp(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaUp);
}

void MoveDown(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaDown);
}

void MoveLeft(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaLeft);
}

void MoveRight(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite) {
	MoveShip(it, shipSlots, shipSprite, lambdaRight);
}

template<typename F>
void MoveShip(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite, F lambdaMove) {
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

void CheckPreviousSlot(std::vector<LineSlot>::iterator& it_around, std::vector<LineSlot>& shipSlots) {
	if (it_around == shipSlots.begin()) {
		it_around = shipSlots.end();
	}
	it_around--;
}

void CheckNextSlot(std::vector<LineSlot>::iterator& it_around, std::vector<LineSlot>& shipSlots) {
	it_around++;
	if (it_around == shipSlots.end()) {
		it_around = shipSlots.begin();
	}
}

bool CanMove(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around, CSimpleSprite* shipSprite, bool canMove) {
	if (canMove) {
		SetSpritePosition(it, it_around, shipSprite);
		return true;
	}

	return false;
}

void SetSpritePosition(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around, CSimpleSprite* shipSprite) {
	it = it_around;
	shipSprite->SetPosition(it->GetCenterX(), it->GetCenterY());
}

void SetSpriteAngle(const std::vector<LineSlot>& vecShips, std::vector<LineSlot>& vecTargets, std::vector<LineSlot>::iterator& it, CSimpleSprite* shipSprite) {
	int enemyIndex = it - vecShips.begin();
	float dy = vecTargets.at(enemyIndex).GetCenterY() - it->GetCenterY();
	float dx = vecTargets.at(enemyIndex).GetCenterX() - it->GetCenterX();
	shipSprite->SetAngle(atan2f(dy, dx) - PI/2);
}
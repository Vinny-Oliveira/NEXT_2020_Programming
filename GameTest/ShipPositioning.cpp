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
		SetShipPosition(it, it_around, shipSprite);
		return true;
	}

	return false;
}

void SetShipPosition(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around, CSimpleSprite* shipSprite) {
	it = it_around;
	shipSprite->SetPosition(it->GetCenterX(), it->GetCenterY());
}
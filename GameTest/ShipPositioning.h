#ifndef _SHIP_POSITIONING_H_
#define _SHIP_POSITIONING_H_

#include <vector>
#include <algorithm>
#include "ShipSlot.h"

// Lambda expression to check if the ship can move down
auto lambdaDown = [](std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around) -> bool { return it_around->GetCenterY() < it->GetCenterY(); };

// Lambda expression to check if the ship can move up
auto lambdaUp = [](std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around) -> bool { return it_around->GetCenterY() > it->GetCenterY(); };

// Lambda expression to check if the ship can move left
auto lambdaLeft = [](std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around) -> bool { return it_around->GetCenterX() < it->GetCenterX(); };

// Lambda expression to check if the ship can move Right
auto lambdaRight = [](std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around) -> bool { return it_around->GetCenterX() > it->GetCenterX(); };

// Handle if the ship can move up and how it moves
void MoveUp(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move down and how it moves
void MoveDown(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move left and how it moves
void MoveLeft(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move right and how it moves
void MoveRight(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move in a specific direction and how it moves
template<typename F>
void MoveShip(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>& shipSlots, CSimpleSprite* shipSprite, F lambdaMove);

// Adjust the iterator to point to the previous available slot in the sequence
void CheckPreviousSlot(std::vector<ShipSlot>::iterator& it_around, std::vector<ShipSlot>& shipSlots);

// Adjust the iterator to point to the next available slot in the sequence
void CheckNextSlot(std::vector<ShipSlot>::iterator& it_around, std::vector<ShipSlot>& shipSlots);

// Check if the ship can move to a determined slot
bool CanMove(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around, CSimpleSprite* shipSprite, bool canMove);

// Set the position of the ship to a new slot
void SetShipPosition(std::vector<ShipSlot>::iterator& it, std::vector<ShipSlot>::iterator& it_around, CSimpleSprite* shipSprite);

// Set the angle of the ship so it points to the proper target
void SetShipAngle(const std::vector<ShipSlot>& vecShips, std::vector<ShipSlot>& vecTargets, std::vector<ShipSlot>::iterator& it, CSimpleSprite* shipSprite);

#endif // !_SHIP_POSITIONING_H_

#ifndef _SHIP_POSITIONING_H_
#define _SHIP_POSITIONING_H_

#include <vector>
#include <algorithm>
#include "LineSlot.h"
#include "Bullet.h"

// Lambda expression to check if the ship can move down
auto lambdaDown = [](std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around) -> bool { return it_around->GetCenterY() < it->GetCenterY(); };

// Lambda expression to check if the ship can move up
auto lambdaUp = [](std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around) -> bool { return it_around->GetCenterY() > it->GetCenterY(); };

// Lambda expression to check if the ship can move left
auto lambdaLeft = [](std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around) -> bool { return it_around->GetCenterX() < it->GetCenterX(); };

// Lambda expression to check if the ship can move Right
auto lambdaRight = [](std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around) -> bool { return it_around->GetCenterX() > it->GetCenterX(); };

// Handle if the ship can move up and how it moves
void MoveUp(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move down and how it moves
void MoveDown(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move left and how it moves
void MoveLeft(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move right and how it moves
void MoveRight(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite);

// Handle if the ship can move in a specific direction and how it moves
template<typename F>
void MoveShip(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>& shipSlots, CSimpleSprite* shipSprite, F lambdaMove);

// Adjust the iterator to point to the previous available slot in the sequence
void CheckPreviousSlot(std::vector<LineSlot>::iterator& it_around, std::vector<LineSlot>& shipSlots);

// Adjust the iterator to point to the next available slot in the sequence
void CheckNextSlot(std::vector<LineSlot>::iterator& it_around, std::vector<LineSlot>& shipSlots);

// Check if the ship can move to a determined slot
bool CanMove(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around, CSimpleSprite* shipSprite, bool canMove);

// Set the position of the sprite to a new slot
void SetSpritePosition(std::vector<LineSlot>::iterator& it, std::vector<LineSlot>::iterator& it_around, CSimpleSprite* sprite);

// Set the angle of the sprite so it points to the proper target
void SetSpriteAngle(const std::vector<LineSlot>& vecShips, std::vector<LineSlot>& vecTargets, std::vector<LineSlot>::iterator& it, CSimpleSprite* sprite);

// Rotate a bullet sprite so it matches the rotation of the ship
void SpritePositionMatch(Bullet& bullet, CSimpleSprite* spriteToMatch);

#endif // !_SHIP_POSITIONING_H_

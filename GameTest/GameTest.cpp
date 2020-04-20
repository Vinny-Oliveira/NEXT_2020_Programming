//------------------------------------------------------------------------
// GameTest.cpp
//------------------------------------------------------------------------
#include "stdafx.h"
//------------------------------------------------------------------------
#include <windows.h> 
#include <math.h>  
//------------------------------------------------------------------------
#include "app\app.h"
//------------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include "PolygonUtil.h"
#include "LineSlot.h"
#include "ShipPositioning.h"
#include "Bullet.h"
#include "EnemyBullet.h"

//------------------------------------------------------------------------
// Game variables
//------------------------------------------------------------------------

// Ship sprite
CSimpleSprite* shipSprite;

// Containers for ship slots and enemy slots
std::vector<LineSlot> shipSlots{};
std::vector<LineSlot> enemySlots{};
std::vector<std::pair<float, float>> shipCoordinates{};
std::vector<std::pair<float, float>> enemyCoordinates{};
std::vector<LineSlot>::iterator shipIterator{ shipSlots.begin() };

// Containers for bullets
std::vector<Bullet> shipBullets;
std::vector<EnemyBullet> enemyBullets;
int maxBullets{ 5 };

// Counters and random index
int kill_count{};
int hangarCount{};
int randTarget{};

// Win and Loss booleans
bool isGameWon{ false };
bool isGameLost{ false };

// Messages for the user
std::string instructions1 = "Move around the outer shape with arrow keys and shoot the inner shape with space.";
std::string instructions2 = "Your bullets are recyclable, but you only have 5!";
std::string kill_score = "Kill count: 0/0";
std::string hangarsRemaining = "Hangars remaining: 0/0";
std::string winMessage = "You win!";
std::string lossMessage = "You lose...";

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init() {

	/* Level specs */
	float sx{ 200.0f };
	float sy{ 200.0f };
	float size{ 500.0f };
	int corners{ 4 };
	float scale{ 0.25f };
	float offset{ 3 * size / 8 };


	// Slots of the outer shape
	shipCoordinates = PolygonUtil::PolygonCoordinates(sx, sy, size, corners);
	PolygonUtil::PopulateShipVector(shipSlots, shipCoordinates, size, corners, shipIterator);

	// Slots of the inner shape
	enemyCoordinates = PolygonUtil::PolygonCoordinates(sx + offset, sy + offset, size * scale, corners);
	PolygonUtil::PopulateShipVector(enemySlots, enemyCoordinates, size, corners);
	kill_score = "Kill count: 0/" + std::to_string(enemySlots.size());
	
	/* Ship sprite */
	shipSprite = App::CreateSprite(".\\TestData\\Ships.bmp", 2, 12);
	shipSprite->SetPosition(sx + size/(2*corners), sy);
	shipSprite->SetFrame(0);	
	shipSprite->SetScale(0.8f);
	SetSpriteAngle(shipSlots, enemySlots, shipIterator, shipSprite);

	/* Ship bullets */
	for (int i{ 0 }; i < maxBullets; i++) {
		shipBullets.emplace_back();
		shipBullets.back().CreateSprite(5);
		shipBullets.back().SetShip(shipSprite);
	}

	// Enemy bullets
	for (int i{ 0 }; i < enemySlots.size(); i++) {
		enemyBullets.emplace_back();
		enemyBullets.back().CreateSprite(11);
	}
}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime) {

	if (isGameWon || isGameLost) {
		return;
	}

	/* Ship movement commands */
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_UP)) {
		MoveUp(shipIterator, shipSlots, shipSprite);
		SetSpriteAngle(shipSlots, enemySlots, shipIterator, shipSprite);
	}

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_DOWN)) {
		MoveDown(shipIterator, shipSlots, shipSprite);
		SetSpriteAngle(shipSlots, enemySlots, shipIterator, shipSprite);
	}

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_LEFT)) {
		MoveLeft(shipIterator, shipSlots, shipSprite);
		SetSpriteAngle(shipSlots, enemySlots, shipIterator, shipSprite);
	}

	if (App::GetController().CheckButton(XINPUT_GAMEPAD_DPAD_RIGHT)) {
		MoveRight(shipIterator, shipSlots, shipSprite);
		SetSpriteAngle(shipSlots, enemySlots, shipIterator, shipSprite);
	}

	/* Ship shoot command */
	if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, true)) {
		for (auto& bullet : shipBullets) {
			if (!bullet.GetLaunched()) {
				bullet.LaunchBullet(enemySlots.at(shipIterator - shipSlots.begin()));
				App::PlaySound(".\\TestData\\Test.wav");
				break;
			}
		}
	}

	/* Handle enemy destruction and if the game has been won */
	for (auto& bullet : shipBullets) {
		if (bullet.GetLaunched() && bullet.GoToTarget()) {
			isGameWon = std::count_if(enemySlots.begin(), enemySlots.end(), [](LineSlot slot) { return slot.IsAlive(); }) < 1;
		}
	}

	/* Control how enemies shoot */
	if (enemyBullets.at(0).GetCanShoot()) {
		srand(time(NULL));

		do {
			randTarget = rand() % enemySlots.size();
		} while (!shipSlots.at(randTarget).IsAlive() && enemyBullets.at(0).GetCanShoot());

		if (!enemyBullets.at(randTarget).GetLaunched()) {
			enemyBullets.at(randTarget).LaunchBullet(enemySlots.at(randTarget), shipSlots.at(randTarget));
		}
	}

	/* Handle how enemies destroy hangars and if the game has been lost */
	for (auto& bullet : enemyBullets) {
		if (bullet.GetLaunched() && bullet.GoToTarget()) {
			enemyBullets.at(0).SetCanShoot(std::count_if(shipSlots.begin(), shipSlots.end(), [](LineSlot slot) { return slot.IsAlive(); }) > 0);
			isGameLost = std::count_if(shipSlots.begin(), shipSlots.end(), [](LineSlot slot) { return slot.IsAlive(); }) < 1;
		}
	}

	/* Update counters */
	kill_count = std::count_if(enemySlots.begin(), enemySlots.end(), [](LineSlot slot) {return !slot.IsAlive(); });
	hangarCount = std::count_if(shipSlots.begin(), shipSlots.end(), [](LineSlot slot) {return slot.IsAlive(); });
}

//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render() {

	// Draw ship slots
	for (auto& ship : shipSlots) {
		ship.DrawSlot();
	}

	// Draw enemy slots
	for (auto& enemy : enemySlots) {
		enemy.DrawSlot();
	}

	// Connect inner and outer slots
	PolygonUtil::ConnectPolygons(shipCoordinates, enemyCoordinates);

	// Draw sprites
	shipSprite->Draw();
	for (auto& bullet : shipBullets) {
		if (bullet.GetLaunched()) {
			bullet.GetBullet()->Draw();
		}
	}
	for (auto& bullet : enemyBullets) {
		if (bullet.GetLaunched()) {
			bullet.GetBullet()->Draw();
		}
	}

	// Text feedback
	if (isGameWon) {
		App::Print(60, 110, winMessage.c_str());
	} else if (isGameLost) {
		App::Print(60, 110, lossMessage.c_str());
	} else {
		App::Print(60, 110, instructions1.c_str());
		App::Print(60, 90, instructions2.c_str());
	}

	kill_score = "Kill count: " + std::to_string(kill_count) + "/" + std::to_string(enemySlots.size());
	hangarsRemaining = "Hangars remaining: " + std::to_string(hangarCount) + "/" + std::to_string(shipSlots.size());
	App::Print(800, 110, kill_score.c_str());
	App::Print(800, 90, hangarsRemaining.c_str());
}

//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown() {

	delete shipSprite;
	
}
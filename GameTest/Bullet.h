#ifndef _BULLET_H_
#define _BULLET_H_

#include <memory>
#include "App/app.h"
#include "LineSlot.h"

class Bullet {
private:
	CSimpleSprite* bulletSprite{ nullptr };
	LineSlot* target{ nullptr };

	//std::shared_ptr<CSimpleSprite> bulletSprite{ nullptr };
	//std::shared_ptr<LineSlot> target{ nullptr };

	bool launched{};
	bool collided{};

	float xPos{};		float yPos{};
	float xTarget{};	float yTarget{};
	float slope{};

public:
	Bullet();
	Bullet(CSimpleSprite sprite, LineSlot lineSlot);
	Bullet(const Bullet& source);
	Bullet(Bullet&& source) noexcept;
	~Bullet();

	auto GetSprite() { return bulletSprite; }
	void SetSprite(CSimpleSprite* sprite) { bulletSprite = sprite; }
	//void SetSprite(CSimpleSprite* sprite) { bulletSprite = std::make_shared<CSimpleSprite>(*sprite); }
	
	bool GetLaunched() { return launched; }
	void SetLaunched(bool isLaunch) { launched = isLaunch; }

	// Launch a bullet towards its target
	void LaunchBullet(const std::vector<LineSlot>::iterator& ship_it, std::vector<LineSlot>& targets, int index);
	
	// Make the bullet travel to its target following a line
	void GoToTarget();
};

#endif // !_BULLET_H_

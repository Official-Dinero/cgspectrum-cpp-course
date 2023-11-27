#pragma once
#include "Point.h"

class Player
{
	Point m_position;
	bool m_hasPowerUp;
	int m_lives;

public:
	Player();
	~Player();

	int GetXPosition() {return m_position.x; }
	int GetYPosition() {return m_position.y; }

	void SetPosition(int x, int y);

	bool HasPowerUp();
	void PickupPowerUp();
	void UsePowerUp();
	int GetLives();
	void TakeDamage();

	void Draw();
};
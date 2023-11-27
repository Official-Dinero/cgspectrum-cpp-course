#pragma once
#include "Player.h"
#include "Level.h"

class Game
{
public:
	Player m_player;
	Level m_level;
	bool m_isGameOver;

	Game();
	~Game();

	void Run();

	bool IsGameOver();

	bool Update();
	void Draw();
};
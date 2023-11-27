#pragma once

class Level
{
	char* m_pLevelData;
	int m_height;
	int m_width;

public:
	Level();
	~Level();

	void Draw(int x, int y);

	bool IsSpace(int x, int y);
	bool IsPowerup(int x, int y);
	bool IsEnemy(int x, int y);
	bool IsGoal(int x, int y);

	void PickupPowerup(int x, int y);
	void RemoveEnemy(int x, int y);

	int GetHeight() { return m_height; }
	int GetWidth() { return m_width; }

private:

	int GetIndexFromCoordinates(int x, int y);

};
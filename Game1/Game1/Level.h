#pragma once
#include <vector>
#include <string>

class PlacableActor;

class Level
{
	char* m_pLevelData;
	int m_height;
	int m_width;

public:
	std::vector<PlacableActor*> m_pActors;

	Level();
	~Level();

	//void Draw(int minY, int maxY, int minX, int maxX);
	void Draw();
	bool Load(std::string levelName, int* playerX, int* playerY);
	PlacableActor* UpdateActors(int x, int y);

	bool IsSpace(int x, int y);
	bool IsWall(int x, int y);
	bool IsFireball(int x, int y);

	int GetHeight() { return m_height; }
	int GetWidth() { return m_width; }

private:
	bool Convert(int* playerX, int* playerY);
	int GetIndexFromCoordinates(int x, int y);

};
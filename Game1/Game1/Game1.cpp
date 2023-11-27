#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game myGame;

	while (!myGame.IsGameOver() && (myGame.m_player.GetLives() > 0))
	{
		myGame.Run();

	}

	myGame.Draw();

	if (myGame.m_player.GetLives() > 0)
	{
		cout << "YOU WON!!!" << endl;
	}
	else
	{
		cout << "You Lost :(" << endl;
	}
}
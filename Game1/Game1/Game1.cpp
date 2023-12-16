#include <iostream>
#include "Game.h"
#include <windows.h>
#include <mmsystem.h>
#include <string>
#include <thread>

#pragma comment(lib, "winmm.lib")

using namespace std;

char input;


int main()
{
	PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	Game myGame;

	if (myGame.Load())
	{
		while (!myGame.IsGameOver())
		{
			myGame.Run();
		}

		if (myGame.DidUserQuit())
		{
			cout << "You Quit!" << endl;
		}
		else if (myGame.m_player.GetLives() < 0)
		{
			PlaySound(0, 0, 0);
			PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << "You Lost :(" << endl;
			cin >> input;
		}
		else
		{
			PlaySound(0, 0, 0);
			PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
			cout << "YOU WON!!!" << endl;
			cin >> input;
		}
	}
}
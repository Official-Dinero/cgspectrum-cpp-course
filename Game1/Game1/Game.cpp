#include "Game.h"
#include <iostream>
#include <conio.h>

using namespace std;

Game::Game()
	: m_isGameOver(false)
{

}

Game::~Game()
{

}

void Game::Run()
{
	Draw();

    cout << "LIVES: " << m_player.GetLives() << endl;
    cout << "HAS POWERUP : " << m_player.HasPowerUp() << endl;

    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();

    newPlayerY++;

    if (m_level.IsSpace(newPlayerX, newPlayerY))
    {
        while (m_level.IsSpace(newPlayerX, newPlayerY))
        {
            m_player.SetPosition(newPlayerX, newPlayerY);
            newPlayerY++;
        }
    }

    newPlayerY--;

	m_isGameOver = Update();

	if (m_isGameOver)
	{
		Draw();
	}
}


bool Game::IsGameOver()
{
	return m_isGameOver;
}

bool Game::Update()
{

    char input = _getch();

    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();

    switch (input)
    {
    case 'a':
    case 'A':
    {
        newPlayerX--;
        break;
    }
    case 'd':
    case 'D':
    {
        newPlayerX++;
        break;
    }
    case 'e':
    case 'E':
    {
        newPlayerY--;
        if (m_level.IsSpace(newPlayerX, newPlayerY))
        {
            m_player.SetPosition(newPlayerX, newPlayerY);
        }
        newPlayerX++;
        if (m_level.IsSpace(newPlayerX, newPlayerY))
        {
            m_player.SetPosition(newPlayerX, newPlayerY);
        }
        newPlayerY--;
        if (m_level.IsSpace(newPlayerX, newPlayerY))
        {
            m_player.SetPosition(newPlayerX, newPlayerY);
        }
        newPlayerX++;
        if (m_level.IsSpace(newPlayerX, newPlayerY))
        {
            m_player.SetPosition(newPlayerX, newPlayerY);
        }
        break;
    }
    case 'q':
    case 'Q':
    {
        newPlayerY--;
        newPlayerX--;
        newPlayerY--;
        newPlayerX--;
        break;
    }
    default:
        break;
    }

    if (m_level.IsSpace(newPlayerX, newPlayerY))
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
    }
    else if (m_level.IsPowerup(newPlayerX, newPlayerY))
    {
        m_level.PickupPowerup(newPlayerX, newPlayerY);
        m_player.PickupPowerUp();
        m_player.SetPosition(newPlayerX, newPlayerY);
    }
    else if (m_level.IsEnemy(newPlayerX, newPlayerY))
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
        m_level.RemoveEnemy(newPlayerX, newPlayerY);
        if (!m_player.HasPowerUp())
        {
        m_player.TakeDamage();
        }
        m_player.UsePowerUp();
    }
    else if (m_level.IsGoal(newPlayerX, newPlayerY))
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
        return true;
    }
    return false;
}

void Game::Draw()
{
    system("cls");
    for (int y = 0; y < m_level.GetHeight(); y++)
    {
        for (int x = 0; x < m_level.GetWidth(); x++)
        {
            if (m_player.GetXPosition() == x && m_player.GetYPosition() == y)
            {
                m_player.Draw();
            }
            else
            {
                m_level.Draw(x, y);
            }

        }
        cout << endl;
    }
}
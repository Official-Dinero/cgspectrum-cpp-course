#include "Game.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Money.h"
#include "FireballActor.h"
#include "FireballPickup.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>


using namespace std;

bool facingright = true;

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;
constexpr int kEscapeKey = 27;
constexpr int kSpaceBar = 32;

Game::Game()
	: m_isGameOver(false)
{

}

Game::~Game()
{

}

bool Game::Load()
{
    return m_level.Load("Level1.txt", m_player.GetXPositionPointer(), m_player.GetYPositionPointer());
}

void Game::Run()
{
	Draw();
    
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

    if (m_player.GetLives() < 0)
    {
        m_isGameOver = true;
    }

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
    int input = _getch();
    int arrowInput = 0;
    int newPlayerX = m_player.GetXPosition();
    int newPlayerY = m_player.GetYPosition();
    int FireballX = m_player.GetXPosition() + 1;
    int FireballY = m_player.GetYPosition();

    if (input == kArrowInput)
    {
        arrowInput = _getch();
    }

    if ((input == kArrowInput && arrowInput == kLeftArrow) ||
        (char)input == 'A' || (char)input == 'a')
    {
        newPlayerX--;
        facingright = false;
    }
    else if ((input == kArrowInput && arrowInput == kRightArrow) ||
        (char)input == 'D' || (char)input == 'd')
    {
        newPlayerX++;
        facingright = true;
    }
    else if ((input == kArrowInput && arrowInput == kUpArrow) ||
        (char)input == 'W' || (char)input == 'w')
    {
        newPlayerY--;
    }
    else if ((input == kArrowInput && arrowInput == kDownArrow) ||
        (char)input == 'S' || (char)input == 's')
    {
        newPlayerY++;
    }
    else if (input == kSpaceBar)
    {
        if (facingright)
        {
            newPlayerY--;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerY--;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
            newPlayerX++;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerX++;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
            newPlayerY++;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerY++;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
        }
        else if (!facingright)
        {
            newPlayerY--;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerY--;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
            newPlayerX--;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerX--;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
            newPlayerY++;
            HandleCollision(newPlayerX, newPlayerY);

            newPlayerY++;
            HandleCollision(newPlayerX, newPlayerY);
            Draw();
        }
    }
    else if ((char)input == 'F' || (char)input == 'f')
    {
        if (m_player.HasFireball())
        {
            m_level.m_pActors.push_back(new FireballActor(newPlayerX+1, newPlayerY, 3, 0));
            m_player.LoseFireball();
        }
    }
    else if (input == kEscapeKey)
    {
        m_UserQuit = true;
        return true;
    }
    else if ((char)input == 'Z' || (char)input == 'z')
    {
        m_player.DropKey();
    }

    if (newPlayerX == m_player.GetXPosition() && newPlayerY == m_player.GetYPosition())
    {
        return false;
    }
    else
    {
        // for loop to go through all actor and check for collision
        return HandleCollision(newPlayerX, newPlayerY);
    }
}

bool Game::HandleCollision(int newPlayerX, int newPlayerY)
{
	PlacableActor* collidedActor = m_level.UpdateActors(newPlayerX, newPlayerY);
	if (collidedActor != nullptr && collidedActor->IsActive())
	{

		Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
        if (collidedEnemy)
        {
            collidedEnemy->Remove();
            m_player.SetPosition(newPlayerX, newPlayerY);

		    m_player.DecrementLives();
            if (m_player.GetLives() < 0)
            {
                return true;
            }
        }
		
		Money* collidedMoney = dynamic_cast<Money*>(collidedActor);
        if (collidedMoney)
        {
		    collidedMoney->Remove();
		    m_player.AddMoney(collidedMoney->GetWorth());
		    m_player.SetPosition(newPlayerX, newPlayerY);
        }

        FireballPickup* collidedFireball = dynamic_cast<FireballPickup*>(collidedActor);
        if (collidedFireball)
        {
            collidedFireball->Remove();
            m_player.PickupFireball();
            m_player.SetPosition(newPlayerX, newPlayerY);
        }

		Key* collidedKey = dynamic_cast<Key*>(collidedActor);
        if (collidedKey)
        {
		    if (!m_player.HasKey())
		    {
			    m_player.PickupKey(collidedKey);
			    collidedKey->Remove();
			    m_player.SetPosition(newPlayerX, newPlayerY);
		    }
        }

		Door* collidedDoor = dynamic_cast<Door*>(collidedActor);
        if (collidedDoor)
        {
		    if (!collidedDoor->IsOpen())
		    {
			    if (m_player.HasKey(collidedDoor->GetColor()))
			    {
				    collidedDoor->Open();
				    collidedDoor->Remove();
				    m_player.UseKey();
				    m_player.SetPosition(newPlayerX, newPlayerY);
			    }
			    else
			    {
                    //Space for door close sound
			    }
		    }
		    else
		    {
			    m_player.SetPosition(newPlayerX, newPlayerY);
		    }
        }

		Goal* collidedGoal = dynamic_cast<Goal*>(collidedActor);
        if (collidedGoal)
        {
		    collidedGoal->Remove();
		    m_player.SetPosition(newPlayerX, newPlayerY);
		    return true;
        }
	}
	else if (m_level.IsSpace(newPlayerX, newPlayerY)) // No collision
	{
		m_player.SetPosition(newPlayerX, newPlayerY);
	}
    else if (m_level.IsFireball(newPlayerX, newPlayerY)) // No collision
    {
        m_player.SetPosition(newPlayerX, newPlayerY);
    }
	else if (m_level.IsWall(newPlayerX, newPlayerY))
	{
		// Wall collision, do nothing
	}
    return false;
}

void Game::Draw()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");

    /*
    int minY = m_player.GetYPosition() - 10;
    if (minY < 0)
    {
        minY = 0;
    }
    int maxY = m_player.GetYPosition() + 10;
    if (maxY > m_level.GetHeight())
    {
        maxY = m_level.GetHeight();
    }
    int minX = m_player.GetXPosition() - 10;
    if (minX < 0)
    {
        minX = 0;
    }
    int maxX = m_player.GetXPosition() + 10;
    if (maxX > m_level.GetWidth())
    {
        maxX = m_level.GetWidth();
    }
    
    m_level.Draw(minY, maxY, minX, maxX);

    */

    m_level.Draw();

    // Set cursor position for player 
    COORD actorCursorPosition;
    actorCursorPosition.X = m_player.GetXPosition();
    actorCursorPosition.Y = m_player.GetYPosition();
    SetConsoleCursorPosition(console, actorCursorPosition);
    m_player.Draw();

    // Set the cursor to the end of the level
    COORD currentCursorPosition;
    currentCursorPosition.X = 0;
    currentCursorPosition.Y = m_level.GetHeight();
    SetConsoleCursorPosition(console, currentCursorPosition);

    cout << "\nX: " << m_player.GetXPosition() << " Y: " << m_player.GetYPosition() << endl;
    cout << "\nControls:" << endl;
    cout << "Arrows or WASD to move" << endl;
    cout << "Space to Jump" << endl;
    cout << "F for fireball" << endl;
    cout << "Z to drop your key" << endl;
    cout << "\nLives: " << m_player.GetLives() << endl;
    cout << "Coins: " << m_player.GetMoney() << endl;
    cout << "Current Key: ";
    if (m_player.HasKey())
    {
        m_player.GetKey()->Draw();
    }
    else
    {
        cout << " ";
    }
    cout << "\nHas Fireball: " << m_player.HasFireball() << endl;
    //cout << minY << " " << maxY << " " << minX << " " << maxX;
}


void Game::HandleCollisionOfFireball(int FireballX, int FireballY)
{
    PlacableActor* collidedActor = m_level.UpdateActors(FireballX, FireballY);
    if (collidedActor != nullptr && collidedActor->IsActive())
    {

        Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);
        if (collidedEnemy)
        {
            collidedEnemy->Remove();
            //Remove Fireball

        }

    }
    else if (m_level.IsSpace(FireballX, FireballY)) 
    {
        // No collision
    }
    else if (m_level.IsWall(FireballX, FireballY))
    {
        // Wall collision, Remove Fireball
    }
}
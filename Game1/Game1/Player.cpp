#include "Player.h"
#include <iostream>

using namespace std;

constexpr char kPlayerSymbol = '@';

Player::Player()
	:m_hasPowerUp(false)
	,m_lives(3)
{

}

Player::~Player()
{

}

void Player::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}

bool Player::HasPowerUp()
{
	return m_hasPowerUp;
}

void Player::PickupPowerUp()
{
	m_hasPowerUp = true;
}

void Player::UsePowerUp()
{
	m_hasPowerUp = false;
}

void Player::Draw()
{
	cout << kPlayerSymbol;
}

int Player::GetLives()
{
	return m_lives;
}

void Player::TakeDamage()
{
	m_lives--;
}
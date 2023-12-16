#include <iostream>

#include "Player.h"
#include "Key.h"

using namespace std;

constexpr int kStartingNumberOfLives = 3;

Player::Player()
	: PlacableActor(0, 0)
	, m_pCurrentKey(nullptr)
	, m_money(0)
	, m_lives(kStartingNumberOfLives)
	, Fireball(false)
{

}

bool Player::HasKey()
{
	return m_pCurrentKey != nullptr;
}

bool Player::HasKey(int color)
{
	return HasKey() && m_pCurrentKey->GetColor() == color;
}

void Player::PickupKey(Key* key)
{
	m_pCurrentKey = key;
}

void Player::UseKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Remove();
		m_pCurrentKey = nullptr;
	}
}

void Player::DropKey()
{
	if (m_pCurrentKey)
	{
		m_pCurrentKey->Place(m_pPosition->x, m_pPosition->y);
		m_pCurrentKey = nullptr;
	}
}

void Player::Draw()
{
	cout << "@";
}

bool Player::HasFireball()
{
	return Fireball;
}

void Player::PickupFireball()
{
	Fireball = true;
}

void Player::LoseFireball()
{
	Fireball = false;
}
#include "Player.h"

void Player::Start() noexcept
{
	m_Sprite->Row = 0;
	m_Sprite->Column = 1;

	m_Transform->Position.x = 100;
	m_Transform->Position.y = 100;
	m_Transform->Scale.x = 2;
	m_Transform->Scale.y = 2;
}

void Player::Update(float deltaTime) noexcept
{
}

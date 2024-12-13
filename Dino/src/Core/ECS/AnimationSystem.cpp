#include "AnimationSystem.h"

void AnimationSystem::UpdateSprite(Sprite& sprite, float deltaTime) noexcept
{
	if (!sprite.Animate)
		return;

	m_FramesCount++;
	m_FramesCount = m_FramesCount % m_TargetFPS;

	sprite.Column = (int)(m_FramesCount * deltaTime * sprite.AnimationSpeed) % sprite.FramesCount;
}

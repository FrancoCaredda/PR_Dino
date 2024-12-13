#pragma once

#include "Components.h"

#include <cstdint>

class AnimationSystem
{
public:
	AnimationSystem(uint32_t targetFPS)
		: m_TargetFPS(targetFPS) {}

	void UpdateSprite(Sprite& sprite, float deltaTime) noexcept;
private:
	uint32_t m_TargetFPS{};
	uint32_t m_FramesCount{};
};
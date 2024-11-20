#pragma once

#include "ECS/Components.h"

#include <cstdint>

class Renderer
{
public:
	Renderer(uint32_t framebufferWidth, uint32_t framebufferHeight)
		: m_FramebufferWidth(framebufferWidth),
		  m_FramebufferHeight(framebufferHeight) {}

	void DrawSprite(const Sprite& sprite, 
		const Transform2D& transform);
private:
	uint32_t m_FramebufferWidth;
	uint32_t m_FramebufferHeight;
};
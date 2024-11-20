#pragma once

#include "ECS/Components.h"

class Renderer
{
public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer(Renderer&&) noexcept = delete;

	void DrawSprite(const Sprite& sprite, 
		const Transform2D& transform);
public:
	static Renderer& GetInstance() noexcept;
private:
	Renderer* s_Instance;
};
#pragma once

#define MAX_ENTITY_COUNT 100

#include "Core/SpriteSheet.h"

#include "Core/ECS/Entity.h"
#include "Core/ECS/Components.h"

#include <array>

class GameLevel
{
public:
	GameLevel(SpriteSheetLibrary& spriteSheetLibrary);
	~GameLevel() = default;

	void Start() noexcept;
	void Update(float deltaTime) noexcept;

	Entity& CreateEntity() noexcept;
private:
	std::array<Entity, MAX_ENTITY_COUNT> m_Entities;
	std::array<Transform2D, MAX_ENTITY_COUNT> m_Transforms;
	std::array<Sprite, MAX_ENTITY_COUNT> m_Sprites;

	int m_NextEntityId = 0;

	SpriteSheetLibrary* m_SpriteSheetLibrary;

	friend class Application;
};
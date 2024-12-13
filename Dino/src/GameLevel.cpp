#include "GameLevel.h"

GameLevel::GameLevel(SpriteSheetLibrary& spriteSheetLibrary)
{
	m_SpriteSheetLibrary = &spriteSheetLibrary;
}

void GameLevel::Start() noexcept
{
	Entity& entity = CreateEntity();
	entity.SpriteComponent->Row = 0;
	entity.SpriteComponent->Column = 0;
	entity.SpriteComponent->Animate = true;
	entity.SpriteComponent->AnimationSpeed = 15;
	entity.SpriteComponent->FramesCount = 7;
	entity.SpriteComponent->SpriteSheetRef = 
		&m_SpriteSheetLibrary->GetSpriteSheet("spritesheet_dino");

	entity.TransformComponent->Position.x = 100;
	entity.TransformComponent->Position.y = 100;
	entity.TransformComponent->Scale.x = 2;
	entity.TransformComponent->Scale.y = 2;
}

void GameLevel::Update(float deltaTime) noexcept
{
}

Entity& GameLevel::CreateEntity() noexcept
{
	m_Entities[m_NextEntityId].EntityId = m_NextEntityId;
	m_Entities[m_NextEntityId].SpriteComponent = &m_Sprites[m_NextEntityId];
	m_Entities[m_NextEntityId].TransformComponent = &m_Transforms[m_NextEntityId];

	m_Transforms[m_NextEntityId].EntityId = m_NextEntityId;
	m_Sprites[m_NextEntityId].EntityId = m_NextEntityId;

	return m_Entities[m_NextEntityId++];
}

#include "GameLevel.h"

GameLevel::GameLevel(SpriteSheetLibrary& spriteSheetLibrary)
{
	m_SpriteSheetLibrary = &spriteSheetLibrary;
}

void GameLevel::Start() noexcept
{
	SpriteSheet& spriteSheet = m_SpriteSheetLibrary->GetSpriteSheet("spritesheet_dino");

	Entity& entity1 = CreateEntity();
	entity1.SpriteComponent->Row = 0;
	entity1.SpriteComponent->Column = 0;
	entity1.SpriteComponent->Animate = true;
	entity1.SpriteComponent->AnimationSpeed = 15;
	entity1.SpriteComponent->FramesCount = 7;
	entity1.SpriteComponent->SpriteSheetRef =
		&spriteSheet;

	entity1.TransformComponent->Position.x = 100;
	entity1.TransformComponent->Position.y = 100;
	entity1.TransformComponent->Scale.x = 2;
	entity1.TransformComponent->Scale.y = 2;

	entity1.BoundingBox->x = 100;
	entity1.BoundingBox->y = 100;
	entity1.BoundingBox->width = spriteSheet.GetCellSize().x * entity1.TransformComponent->Scale.x;
	entity1.BoundingBox->height = spriteSheet.GetCellSize().y * entity1.TransformComponent->Scale.y;

	Entity& entity2 = CreateEntity();
	entity2.SpriteComponent->Row = 0;
	entity2.SpriteComponent->Column = 0;
	entity2.SpriteComponent->SpriteSheetRef =
		&spriteSheet;

	entity2.TransformComponent->Position.x = 150;
	entity2.TransformComponent->Position.y = 150;
	entity2.TransformComponent->Scale.x = 2;
	entity2.TransformComponent->Scale.y = 2;

	entity2.BoundingBox->x = 150;
	entity2.BoundingBox->y = 150;
	entity2.BoundingBox->width = spriteSheet.GetCellSize().x * entity2.TransformComponent->Scale.x;
	entity2.BoundingBox->height = spriteSheet.GetCellSize().y * entity2.TransformComponent->Scale.y;
}

void GameLevel::Update(float deltaTime) noexcept
{
}

Entity& GameLevel::CreateEntity() noexcept
{
	m_Entities[m_NextEntityId].EntityId = m_NextEntityId;
	m_Entities[m_NextEntityId].SpriteComponent = &m_Sprites[m_NextEntityId];
	m_Entities[m_NextEntityId].TransformComponent = &m_Transforms[m_NextEntityId];
	m_Entities[m_NextEntityId].BoundingBox = &m_BoundingBoxes[m_NextEntityId];

	m_Transforms[m_NextEntityId].EntityId = m_NextEntityId;
	m_Sprites[m_NextEntityId].EntityId = m_NextEntityId;

	m_BoundingBoxes[m_NextEntityId] = Rectangle{};

	return m_Entities[m_NextEntityId++];
}

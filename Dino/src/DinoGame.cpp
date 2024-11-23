#include "DinoGame.h"
#include "Entities/Player.h"

void DinoGame::Init() noexcept
{
	AGame::Init();

	SpriteSheetLibrary& library = GetSpriteSheetLibrary();
	std::filesystem::current_path(ASSETS_DIRECTORY);

	SpriteSheet& spriteSheet = library.LoadSpriteSheet(std::filesystem::path("spritesheet_dino.png"), 
		Vector2{58, 42});

	SetCurrentScene(&m_Scene);

	Player* player = m_Scene.CreateEntity<Player>();
	player->SetSpriteSheet(spriteSheet);
}


void DinoGame::Update(float deltaTime)
{
}

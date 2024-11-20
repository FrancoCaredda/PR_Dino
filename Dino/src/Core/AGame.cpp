#include "AGame.h"

#include "raylib.h"

#include <stdexcept>

AGame* AGame::s_Instance = nullptr;

AGame::AGame()
{
	if (s_Instance)
		throw std::runtime_error::exception("There cannot be two instances of the AGame class");

	s_Instance = this;
}

void AGame::Init() noexcept
{
	InitWindow(1920, 1080, "Chrome Dino - Clone");
}

void AGame::Run() noexcept
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Color{});

		Update(0);

		if (m_CurrentScene)
		{
			auto& sprites = m_CurrentScene->GetSprites();
			auto& transforms = m_CurrentScene->GetTransforms();

			for (int i = 0; i < MAX_ENTITY_COUNT; i++)
			{
				if (sprites[i].EntityId != -1)
					m_Renderer.DrawSprite(sprites[i], transforms[i]);
			}
		}

		EndDrawing();
	}
}

void AGame::Close() noexcept
{
	CloseWindow();
}

void AGame::SetCurrentScene(Scene* scene)
{
	m_CurrentScene = scene;
}


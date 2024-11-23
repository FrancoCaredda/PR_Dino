#include "AGame.h"

#include "raylib.h"

#include <stdexcept>
#include <chrono>

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
	auto& entities = m_CurrentScene->GetEntities();

	for (int i = 0; i < m_CurrentScene->GetEntityCount(); i++)
		entities[i]->Start();

	auto prev = std::chrono::high_resolution_clock::now();
	while (!WindowShouldClose())
	{
		auto now = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> deltaTime = now - prev;
		float deltaTimeSeconds = deltaTime.count();

		prev = now;

		BeginDrawing();
		ClearBackground(RAYWHITE);

		Update(deltaTimeSeconds);

		for (int i = 0; i < m_CurrentScene->GetEntityCount(); i++)
			entities[i]->Update(deltaTimeSeconds);

		if (m_CurrentScene)
		{
			auto& sprites = m_CurrentScene->GetSprites();
			auto& transforms = m_CurrentScene->GetTransforms();

			for (int i = 0; i < m_CurrentScene->GetEntityCount(); i++)
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


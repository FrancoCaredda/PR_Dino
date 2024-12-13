#include "Application.h"

#include "raylib.h"

#include <chrono>

void Application::Init()
{
	InitWindow(1920, 1080, "Chrome Dino - Clone");
	SetTargetFPS(60);
	std::filesystem::current_path(ASSETS_DIRECTORY);

	m_SpriteSheetLibrary.LoadSpriteSheet(
		std::filesystem::path("spritesheet_dino.png"), 
		Vector2{58, 42}
	);

	m_Level.Start();
}

void Application::Run()
{
	auto prev = std::chrono::high_resolution_clock::now();
	while (!WindowShouldClose())
	{
		auto now = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> deltaTime = now - prev;
		float deltaTimeSeconds = deltaTime.count();

		prev = now;

		BeginDrawing();
		ClearBackground(RAYWHITE);

		m_Level.Update(deltaTimeSeconds);
		for (Entity& entity : m_Level.m_Entities)
		{
			Transform2D* transform = entity.TransformComponent;
			Sprite* sprite = entity.SpriteComponent;

			if (entity.EntityId != -1)
			{
				m_AnimationSystem.UpdateSprite(*sprite, deltaTimeSeconds);
				m_Renderer.DrawSprite(*sprite, *transform);
				m_Renderer.DebugRect(*entity.BoundingBox);
			}
		}

		EndDrawing();
	}
}

void Application::Close()
{
	CloseWindow();
}

#include "AApplication.h"

#include "raylib.h"

#include <stdexcept>

AApplication* AApplication::s_Instance = nullptr;

AApplication::AApplication()
{
	if (s_Instance)
		throw std::runtime_error::exception("There cannot be two instances of the AApplication class");

	s_Instance = this;
}

void AApplication::Init() noexcept
{
	InitWindow(1920, 1080, "Chrome Dino - Clone");
}

void AApplication::Run() noexcept
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(Color{});

		EndDrawing();
	}
}

void AApplication::Close() noexcept
{
	CloseWindow();
}



#pragma once

#include "raylib.h"
#include "Core/SpriteSheet.h"

struct Component
{
	int EntityId = -1;
};

struct Transform2D : public Component
{
	Vector2 Position{};
	Vector2	Scale{};
};

struct Sprite : public Component
{
	int Row{};
	int Column{};

	SpriteSheet* SpriteSheetRef;
};
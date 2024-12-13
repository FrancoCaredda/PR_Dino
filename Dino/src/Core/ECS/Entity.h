#pragma once

#include "Components.h"

struct Entity
{
	int EntityId = -1;

	Transform2D* TransformComponent = nullptr;
	Sprite* SpriteComponent = nullptr;
	Rectangle* BoundingBox = nullptr;
};
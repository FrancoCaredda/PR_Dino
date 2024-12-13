#pragma once

#include "raylib.h"

namespace PhysicsSystem
{
	bool CheckCollision(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept;
}
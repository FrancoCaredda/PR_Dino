#include "Renderer.h"

#include <stdexcept>

void Renderer::DrawSprite(const Sprite& sprite, const Transform2D& transform)
{
	Vector2 origin = sprite.SpriteSheetRef->GetPixelCoordinates(sprite.Row, sprite.Column);
	Vector2 cellSize = sprite.SpriteSheetRef->GetCellSize();

	Rectangle source{
		origin.x, origin.y,
		cellSize.x, cellSize.y
	};

	Rectangle destination{
		0,
		0,
		cellSize.x * transform.Scale.x,
		cellSize.y * transform.Scale.y
	};

	DrawTexturePro(sprite.SpriteSheetRef->GetNative(), source, destination,
		Vector2{ -transform.Position.x, -transform.Position.y }, 0, RAYWHITE);
}

void Renderer::DebugRect(const Rectangle& rect)
{
	DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, Color{ 0, 255, 0, 255 });
}

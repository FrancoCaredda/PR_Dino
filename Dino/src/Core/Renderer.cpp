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
		transform.Position.x,
		transform.Position.y,
		cellSize.x * transform.Scale.x,
		cellSize.y * transform.Scale.y
	};

	DrawTexturePro(sprite.SpriteSheetRef->GetNative(), source, destination,
		Vector2{ -transform.Position.x, -transform.Position.y }, 0, RAYWHITE);
}

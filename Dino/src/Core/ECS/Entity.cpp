#include "Entity.h"

void AEntity::SetSpriteSheet(SpriteSheet& spriteSheet) noexcept
{
	m_Sprite->SpriteSheetRef = &spriteSheet;
}

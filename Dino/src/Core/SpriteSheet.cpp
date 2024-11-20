#include "SpriteSheet.h"

#include <stdexcept>

SpriteSheet::SpriteSheet(SpriteSheet&& spriteSheet) noexcept
{
	m_Texture = spriteSheet.m_Texture;
	m_CellSize = spriteSheet.m_CellSize;

	spriteSheet.m_Texture = Texture2D();
}

SpriteSheet::~SpriteSheet()
{
	if (IsTextureReady(m_Texture))
		UnloadTexture(m_Texture);
}

SpriteSheet& SpriteSheet::operator=(SpriteSheet&& spriteSheet) noexcept
{
	m_Texture = spriteSheet.m_Texture;
	m_CellSize = spriteSheet.m_CellSize;

	spriteSheet.m_Texture = Texture2D();
	return *this;
}

const SpriteSheet& SpriteSheetLibrary::LoadSpriteSheet(const std::filesystem::path& path,
	Vector2 cellSize)
{
	if (!std::filesystem::exists(path))
	{
		std::string message = std::string("File not found: ") + path.string();
		throw std::runtime_error::exception(message.c_str());
	}

	std::string filename = path.filename().string();
	std::string key = filename.substr(0, 
		filename.find('.', 0));

	Texture2D texture = LoadTexture(path.string().c_str());
	m_SpriteSheets[key] = SpriteSheet(texture, cellSize);

	return m_SpriteSheets[key];
}

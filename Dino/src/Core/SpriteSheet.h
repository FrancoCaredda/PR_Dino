#pragma once

#include "raylib.h"

#include <cstdint>
#include <filesystem>
#include <unordered_map>
#include <string>

class SpriteSheet
{
public:
	SpriteSheet() = default;
	SpriteSheet(Texture2D texture, Vector2 cellSize)
		: m_Texture(texture), m_CellSize(cellSize) {}
	SpriteSheet(SpriteSheet&& spriteSheet) noexcept;
	~SpriteSheet();

	inline Vector2 GetCellSize() const noexcept { return m_CellSize; }
	inline Vector2 GetTextureSize() const noexcept { return Vector2{
			(float)m_Texture.width, (float)m_Texture.height }; }

	inline Vector2 GetPixelCoordinates(uint32_t row, uint32_t column) const noexcept { 
		return Vector2{ m_CellSize.x * column, m_CellSize.y * row}; }

	inline Texture2D GetNative() const noexcept { return m_Texture; }

	SpriteSheet& operator=(SpriteSheet&& spriteSheet) noexcept;
private:
	Texture2D m_Texture;
	Vector2 m_CellSize;
};

class SpriteSheetLibrary
{
public:
	SpriteSheetLibrary() = default;
	SpriteSheetLibrary(const SpriteSheet&) = delete;
	SpriteSheetLibrary(SpriteSheet&&) noexcept = delete;

	const SpriteSheet& LoadSpriteSheet(const std::filesystem::path& path,
		Vector2 cellSize);

	inline const SpriteSheet& GetSpriteSheet(const std::string& name) const noexcept { return m_SpriteSheets.at(name); }
private:
	std::unordered_map<std::string, SpriteSheet> m_SpriteSheets;
};
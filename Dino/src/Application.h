#pragma once

#include "GameLevel.h"

#include "Core/Renderer.h"
#include "Core/SpriteSheet.h"

#include "Core/ECS/AnimationSystem.h"

class Application
{
public:
	Application() = default;

	void Init();
	void Run();
	void Close();
private:
	SpriteSheetLibrary m_SpriteSheetLibrary{};
	Renderer m_Renderer{ 1920, 1080 };

	AnimationSystem m_AnimationSystem{ 60 };

	GameLevel m_Level{m_SpriteSheetLibrary};
};
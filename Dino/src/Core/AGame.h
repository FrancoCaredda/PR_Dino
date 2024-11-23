#pragma once

#include "Scene.h"
#include "Renderer.h"
#include "SpriteSheet.h"

class AGame
{
public:
	AGame();
	AGame(const AGame&) = delete;
	AGame(AGame&&) = delete;

	virtual void Init() noexcept;
	void Run() noexcept;
	void Close() noexcept;

	void SetCurrentScene(Scene* scene);

	inline Scene& GetCurrentScene() const noexcept { return *m_CurrentScene; }
	inline Renderer& GetRenderer() const noexcept { return m_Renderer; }
	inline SpriteSheetLibrary& GetSpriteSheetLibrary() const noexcept { return m_SpriteSheetLibrary; }
private:
	void ProcessScene(float deltaTime) noexcept;
protected:
	virtual void Update(float deltaTime) = 0;
private:
	mutable Scene* m_CurrentScene = nullptr;
	mutable Renderer m_Renderer{1920, 1080};
	mutable SpriteSheetLibrary m_SpriteSheetLibrary;
private:
	static AGame* s_Instance;
};
#pragma once

#include "Core/AGame.h"

class DinoGame : public AGame
{
public:
	DinoGame()
		: AGame() {}

	virtual void Init() noexcept override;

protected:
	virtual void Update(float deltaTime) override;
private:
	Scene m_Scene;
};
#pragma once

#include "Core/AGame.h"

class DinoApplication : public AGame
{
public:
	DinoApplication()
		: AGame() {}

	virtual void Init() noexcept override;

protected:
	virtual void Update(float deltaTime) override;
};
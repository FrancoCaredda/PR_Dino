#pragma once

#include "Core/ECS/Entity.h"

class Player : public AEntity
{
public:
	Player(int entityId,
		Sprite* sprite,
		Transform2D* transform)
		: AEntity(entityId, sprite, transform) {}

	virtual void Start() noexcept override;
	virtual void Update(float deltaTime) noexcept override;
};
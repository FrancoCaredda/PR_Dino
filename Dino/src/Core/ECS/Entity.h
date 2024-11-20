#pragma once

#include "Components.h"

#include <array>
#include <vector>
#include <type_traits>
#include <stdexcept>

class AEntity
{
public:
	AEntity(int entityId,
		Sprite* sprite,
		Transform2D* transform)
		: m_EntityId(entityId), m_Sprite(sprite), m_Transform(transform) {}

	virtual void Start() noexcept = 0;
	virtual void Update(float deltaTime) noexcept = 0;

	inline int GetEntityId() const noexcept { return m_EntityId; }
protected:
	Sprite* m_Sprite;
	Transform2D* m_Transform;
private:
	int m_EntityId;
};
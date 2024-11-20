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

#define MAX_ENTITY_COUNT 100
class EntityPool
{
public:
	EntityPool();
	EntityPool(const EntityPool&) = delete;
	EntityPool(EntityPool&&) noexcept = delete;

	~EntityPool();

	template<typename TEntity>
	TEntity* CreateEntity() noexcept
	{
		static_assert(constexpr std::is_base_of<AEntity, TEntity>(), 
			"TEntity has to be of type AEntity");

		if (m_CurrentEntity >= MAX_ENTITY_COUNT)
			throw std:::runtime_error::exception("Entity overflow exception!");

		Sprite* sprite = &m_Sprites[m_CurrentEntity];
		Transform2D* transform = m_Transforms[m_CurrentEntity];

		sprite->EntityId = m_CurrentEntity;
		transform->EntityId = m_CurrentEntity;

		TEntity* entity = new TEntity(m_CurrentEntity, sprite, transform);
		m_Entities[m_CurrentEntity++] = entity;

		return entity;
	}

	inline const std::array<Transform2D, MAX_ENTITY_COUNT>& GetTransforms() const noexcept { return m_Transforms; }
	inline const std::array<Sprite, MAX_ENTITY_COUNT>& GetSprites() const noexcept { return m_Sprites; }
public:
	static EntityPool& GetInstance() noexcept;
private:
	static EntityPool* s_Instance;
private:
	std::array<Transform2D, MAX_ENTITY_COUNT> m_Transforms;
	std::array<Sprite, MAX_ENTITY_COUNT> m_Sprites;
	std::array<AEntity*, MAX_ENTITY_COUNT> m_Entities;

	int m_CurrentEntity = 0;
};
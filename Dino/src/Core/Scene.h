#pragma once

#include "ECS/Entity.h"

#define MAX_ENTITY_COUNT 100
class Scene
{
public:
	Scene() = default;
	Scene(const Scene&) = delete;
	Scene(Scene&&) noexcept = delete;

	~Scene() = default;

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
private:
	std::array<Transform2D, MAX_ENTITY_COUNT> m_Transforms;
	std::array<Sprite, MAX_ENTITY_COUNT> m_Sprites;
	std::array<AEntity*, MAX_ENTITY_COUNT> m_Entities;

	int m_CurrentEntity = 0;
};
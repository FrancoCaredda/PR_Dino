#include "Entity.h"

EntityPool* EntityPool::s_Instance = nullptr;

EntityPool::EntityPool()
{
	if (s_Instance)
		throw std::runtime_error::exception("There cannot be two instances of the EntityPool class");

	s_Instance = this;
}

EntityPool::~EntityPool()
{
	for (AEntity* entity : m_Entities)
		delete entity;
}

EntityPool& EntityPool::GetInstance() noexcept
{
	return *s_Instance;
}
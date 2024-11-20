#pragma once

#include "Core/ECS/Entity.h"

class AApplication
{
public:
	AApplication();
	AApplication(const AApplication&) = delete;
	AApplication(AApplication&&) = delete;

	virtual void Init() noexcept;
	void Run() noexcept;
	void Close() noexcept;
protected:
	EntityPool m_Pool;
private:
	static AApplication* s_Instance;
};
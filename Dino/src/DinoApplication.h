#pragma once

#include "Core/AApplication.h"

class DinoApplication : public AApplication
{
public:
	DinoApplication()
		: AApplication() {}

	virtual void Init() noexcept override;
};
#include "PhysicsSystem.h"

namespace PhysicsSystem
{
	static bool IsALeftToB(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept
	{
		float Ax = boundingBox1.x + boundingBox1.width;
		float Bx = boundingBox2.x;

		return Ax < Bx;
	}
	static bool IsARightToB(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept
	{
		float Ax = boundingBox1.x;
		float Bx = boundingBox2.x + boundingBox2.width;

		return Ax > Bx;
	}
	static bool IsAAboveB(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept
	{
		float Ay = boundingBox1.y + boundingBox1.height;
		float By = boundingBox2.y;

		return Ay < By;
	}
	static bool IsABelowB(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept
	{
		float Ay = boundingBox1.y;
		float By = boundingBox2.y + boundingBox2.height;

		return Ay > By;
	}

	bool CheckCollision(const Rectangle& boundingBox1, const Rectangle& boundingBox2) noexcept
	{
		return !IsALeftToB(boundingBox1, boundingBox2)   &&
			   !IsARightToB(boundingBox1, boundingBox2)  &&
			   !IsAAboveB(boundingBox1, boundingBox2)    &&
			   !IsABelowB(boundingBox1, boundingBox2);
	}
}
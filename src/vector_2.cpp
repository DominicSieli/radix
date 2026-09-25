#include <cmath>

#include "vector_2.h"

namespace Radix
{
	Vector2::Vector2()
	{}

	Vector2::~Vector2()
	{}

	Vector2::Vector2(float x, float y)
		: x{x}, y{y}
	{}

	float Vector2::distance(Vector2 position_1, Vector2 position_2)
	{
		float dx = position_2.x - position_1.x;
		float dy = position_2.y - position_1.y;

		return std::sqrt(dx * dx + dy * dy);
	}
}

#include <cmath>
#include "vector2.h"

namespace radix
{
	Vector2 create_vector2(float x, float y)
	{
		return {x, y};
	}

	float distance(const Vector2& point1, const Vector2& point2)
	{
		float dx = point2.x - point1.x;
		float dy = point2.y - point1.y;

		return std::sqrt(dx * dx + dy * dy);
	}
}

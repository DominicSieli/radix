#include <cmath>

#include "math.h"

namespace Radix
{
	float distance(const Vector2<float>& point_1, const Vector2<float>& point_2)
	{
		float x = point_2.x - point_1.x;
		float y = point_2.y - point_1.y;

		return std::sqrt(x * x + y * y);
	}
}

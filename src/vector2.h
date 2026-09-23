#ifndef VECTOR2_H
#define VECTOR2_H

namespace Radix
{
	struct Vector2
	{
		float x;
		float y;
	};

	Vector2 create_vector2(float, float);

	float distance(Vector2, Vector2);
}

#endif

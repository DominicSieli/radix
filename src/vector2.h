#ifndef VECTOR2_H
#define VECTOR2_H

namespace radix
{
	struct Vector2
	{
		float x;
		float y;
	};

	Vector2 create_vector2(float, float);

	float distance(const Vector2&, const Vector2&);
}

#endif

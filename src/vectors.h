#ifndef VECTORS_H
#define VECTORS_H

namespace Radix
{
	template<typename T>
	struct Vector2
	{
		T x;
		T y;
	};

	template<typename T>
	struct Vector3
	{
		T x;
		T y;
		T z;
	};

	template<typename T>
	struct Vector4
	{
		T x;
		T y;
		T w;
		T h;
	};
}

#endif

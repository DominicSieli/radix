#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <cmath>

namespace Radix
{
	template<typename T>
	class Vector2
	{
		public:
			T x;
			T y;

			Vector2()
			{}

			Vector2(const T& x, const T& y):
				x{x}, y{y}
			{}

			inline static T distance(const Vector2<T>& position_1, const Vector2<T>& position_2)
			{
				T dx = position_2.x - position_1.x;
				T dy = position_2.y - position_1.y;

				return std::sqrt(dx * dx + dy * dy);
			}
	};

}

#endif

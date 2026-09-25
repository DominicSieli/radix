#ifndef VECTOR_2_H
#define VECTOR_2_H

namespace Radix
{
	class Vector2
	{
		public:
			float x;
			float y;

			Vector2();

			~Vector2();

			Vector2(float, float);

			static float distance(Vector2, Vector2);
	};

}

#endif

#ifndef COLLISION_H
#define COLLISION_H

namespace Radix
{
	class Collision
	{
		public:
			unsigned int collider_tag_1;
			unsigned int collider_tag_2;
			unsigned int collision_type;

			Collision(const unsigned int&, const unsigned int&, const unsigned int&);
	};
}

#endif

#ifndef COLLISION_H
#define COLLISION_H

namespace Radix
{
	class Collision
	{
		private:
			unsigned int collider_tag_1;
			unsigned int collider_tag_2;
			unsigned int collision_type;

		public:
			Collision(const unsigned int&, const unsigned int&, const unsigned int&);

			unsigned int get_collider_tag_1() const;

			unsigned int get_collider_tag_2() const;

			unsigned int get_collision_type() const;
	};
}

#endif

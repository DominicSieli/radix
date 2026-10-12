#include "collision.h"

namespace Radix
{
	Collision::Collision(const unsigned int& collider_tag_1, const unsigned int& collider_tag_2, const unsigned int& collision_type):
		collider_tag_1{collider_tag_1}, collider_tag_2{collider_tag_2}, collision_type{collision_type}
	{}


	unsigned int Collision::get_collider_tag_1() const
	{
		return collider_tag_1;
	}

	unsigned int Collision::get_collider_tag_2() const
	{
		return collider_tag_2;
	}

	unsigned int Collision::get_collision_type() const
	{
		return collision_type;
	}
}

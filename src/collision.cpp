#include "collision.h"

namespace Radix
{
	Collision::Collision(const unsigned int& collider_tag_1, const unsigned int& collider_tag_2, const unsigned int& collision_type):
		collider_tag_1{collider_tag_1}, collider_tag_2{collider_tag_2}, collision_type{collision_type}
	{}
}

#include "collision.h"

namespace Radix
{
	Collision::Collision()
	{}

	Collision::Collision(unsigned int collider_tag_1, unsigned int collider_tag_2, unsigned int collision_type)
		: collider_tag_1{collider_tag_1}, collider_tag_2{collider_tag_2}, collision_type{collision_type}
	{}

	Collision::~Collision()
	{}
}

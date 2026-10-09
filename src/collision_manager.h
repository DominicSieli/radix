#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include <SDL3/SDL.h>

#include "collision.h"

namespace Radix
{
	class CollisionManager
	{
		public:
			CollisionManager();

			unsigned int check_collisions(const std::vector<Collision>&, const unsigned int&);

			bool check_rect_collision(const SDL_Rect&, const SDL_Rect&);
	};
}

#endif
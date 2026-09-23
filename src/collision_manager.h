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

			~CollisionManager();

			unsigned int check_collisions(const std::vector<Collision>&, unsigned int);

			bool check_rect_collision(SDL_Rect, SDL_Rect);
	};
}

#endif
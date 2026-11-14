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

			unsigned int check_geometry_collisions(const std::vector<Collision>&, const unsigned int&);

			bool check_geometry_collision(const std::vector<SDL_FPoint>&, const std::vector<SDL_FPoint>&);

			bool check_axes(const std::vector<SDL_FPoint>&, const std::vector<SDL_FPoint>&);
	};
}

#endif
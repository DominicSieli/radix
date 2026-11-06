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

			unsigned int check_rect_collisions(const std::vector<Collision>&, const unsigned int&);

			unsigned int check_geometry_collisions(const std::vector<Collision>&, const unsigned int&);

			bool check_rect_collision(const SDL_FRect&, const SDL_FRect&);

			bool check_geometry_collision(const std::vector<SDL_FPoint>&, const std::vector<SDL_FPoint>&);
	};
}

#endif
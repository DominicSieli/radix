#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include <SDL3/SDL.h>

#include "collision.h"
#include "entity_manager.h"

namespace Radix
{
	class CollisionManager
	{
		private:
			EntityManager* entity_manager;

		public:
			CollisionManager();

			CollisionManager(EntityManager*);

			~CollisionManager();

			unsigned int check_collisions(const std::vector<Collision>&, unsigned int);

			bool check_rect_collision(SDL_Rect, SDL_Rect);
	};
}

#endif
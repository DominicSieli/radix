#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

namespace radix
{
	class Collision
	{
		public:
			static bool check_rectangle_collision(const SDL_Rect&, const SDL_Rect&);
	};
}

#endif
#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include <SDL3/SDL.h>

namespace Radix
{
	class RenderManager
	{
		private:
			SDL_Renderer* renderer;

		public:
			RenderManager();

			~RenderManager();

			bool initialize(SDL_Window*, const char*);

			SDL_Renderer* get_renderer();

			void render(const unsigned int&);

			void destroy();
	};
}

#endif
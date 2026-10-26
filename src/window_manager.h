#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <SDL3/SDL.h>

#include "vectors.h"

namespace Radix
{
	class WindowManager
	{
		private:
			SDL_Window* window = nullptr;

		public:
			WindowManager();

			~WindowManager();

			bool initialize(const int&, const int&);

			SDL_Window* get_window();

			void update_resolution(const int&, const int&);
	};
}

#endif

#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SDL3/SDL.h>

namespace Radix
{
	class InputManager
	{
		private:
			SDL_Event input_event;

		public:
			InputManager();

			~InputManager();

			void poll();

			SDL_Event get_event();
	};
}

#endif

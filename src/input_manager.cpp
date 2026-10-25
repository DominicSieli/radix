#include "input_manager.h"

namespace Radix
{
	InputManager::InputManager()
	{}

	InputManager::~InputManager()
	{}

	void InputManager::poll()
	{
		SDL_PollEvent(&input_event);
	}

	SDL_Event InputManager::get_event()
	{
		return input_event;
	}
}

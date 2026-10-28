#include <SDL3_ttf/SDL_ttf.h>

#include "window_manager.h"

namespace Radix
{
	WindowManager::WindowManager()
	{}

	WindowManager::~WindowManager()
	{}

	bool WindowManager::initialize(const int& resolution_x, const int& resolution_y)
	{
		bool sdl_init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

		if(!sdl_init)
		{
			return false;
		}

		bool ttf_init = TTF_Init();

		if(!ttf_init)
		{
			return false;
		}

		window = SDL_CreateWindow(nullptr, resolution_x, resolution_y, SDL_WINDOW_BORDERLESS);

		if(!window)
		{
			return false;
		}

		SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

		return true;
	}

	SDL_Window* WindowManager::get_window()
	{
		return window;
	}

	void WindowManager::update_resolution(const int& x, const int& y)
	{
		SDL_SetWindowSize(window, x, y);
	}
}

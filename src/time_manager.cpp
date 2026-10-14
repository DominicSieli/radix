#include "time_manager.h"

namespace Radix
{
	TimeManager::TimeManager():
		delta_time{}
	{}

	TimeManager::~TimeManager()
	{}

	float TimeManager::get_fps()
	{
		return fps;
	}

	void TimeManager::calculate_fps()
	{
		fps = 1.00f / delta_time;
	}

	float TimeManager::get_delta_time()
	{
		return delta_time;
	}

	void TimeManager::calculate_delta_time(const unsigned int& frame_target_time)
	{
		previous_tick = 0;
		frameStart = SDL_GetTicks();
		frameTime = SDL_GetTicks() - frameStart;

		if(frameTime < frame_target_time)
		{
			SDL_Delay(frame_target_time - frameTime);
		}

		delta_time = (SDL_GetTicks() - previous_tick) / 1000.00f;
		previous_tick = SDL_GetTicks();

		delta_time = (delta_time > 0.05f) ? 0.05f : delta_time;
	}
}

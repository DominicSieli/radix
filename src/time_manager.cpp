#include "time_manager.h"

namespace Radix
{
	TimeManager::TimeManager()
	{}

	TimeManager::~TimeManager()
	{}

	float TimeManager::get_fps()
	{
		return fps;
	}

	float TimeManager::get_delta_time()
	{
		return delta_time;
	}

	void TimeManager::calculate_fps()
	{
		const Uint64 current_tick = SDL_GetPerformanceCounter();

		elapsed_ticks += current_tick - previous_tick;
		previous_tick = current_tick;

		++frame_count;

		if(elapsed_ticks >= frequency)
		{
			fps = static_cast<float>(frame_count) * static_cast<float>(frequency) / static_cast<float>(elapsed_ticks);

			frame_count = 0;
			elapsed_ticks = 0;
		}
	}

	void TimeManager::calculate_delta_time()
	{
		const Uint64 current_time = SDL_GetPerformanceCounter();

		delta_time = static_cast<float>(current_time - previous_time) / static_cast<float>(frequency);
		previous_time = current_time;
	}

	void TimeManager::cap_fps(const unsigned int& fps_cap)
	{
		Uint64 frame_start = SDL_GetTicks();
		Uint64 frame_time = SDL_GetTicks() - frame_start;
		const float target_frame_time = 1000.00f / static_cast<float>(fps_cap);

		if(static_cast<float>(frame_time) < target_frame_time)
		{
			SDL_Delay(static_cast<Uint64>(target_frame_time) - frame_time);
		}
	}
}

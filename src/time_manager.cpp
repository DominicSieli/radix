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

	void TimeManager::calculate_fps()
	{
		Uint64 current_tick = SDL_GetPerformanceCounter();

		++frame_count;
		previous_tick = current_tick;
		elapsed_time = static_cast<float>(current_tick - fps_timer) / static_cast<float>(SDL_GetPerformanceFrequency());

		if(elapsed_time >= 1.00f)
		{
			fps = static_cast<float>(frame_count) / elapsed_time;

			frame_count = 0;
			fps_timer = current_tick;
		}
	}

	float TimeManager::get_delta_time()
	{
		return delta_time;
	}

	void TimeManager::calculate_delta_time(const float& target_frame_time)
	{
		Uint64 frame_start = SDL_GetTicks();
		Uint64 frame_time = SDL_GetTicks() - frame_start;

		if(static_cast<float>(frame_time) < target_frame_time)
		{
			SDL_Delay(static_cast<Uint64>(target_frame_time) - frame_time);
		}

		delta_time = (SDL_GetTicks() - previous_tick) / 1000.00f;
		previous_tick = SDL_GetTicks();

		delta_time = (delta_time > 0.05f) ? 0.05f : delta_time;
	}
}

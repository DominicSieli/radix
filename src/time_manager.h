#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SDL3/SDL.h>

namespace Radix
{
	class TimeManager
	{
		private:
			float fps;
			float delta_time;
			Uint64 frame_count;
			Uint64 elapsed_ticks;
			Uint64 fps_timer = SDL_GetPerformanceCounter();
			Uint64 frequency = SDL_GetPerformanceFrequency();
			Uint64 previous_time = SDL_GetPerformanceCounter();
			Uint64 previous_tick = SDL_GetPerformanceCounter();

		public:
			TimeManager();

			~TimeManager();

			float get_fps();

			float get_delta_time();

			void calculate_fps();

			void calculate_delta_time();

			void cap_fps(const unsigned int&);
	};
}

#endif

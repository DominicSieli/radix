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
			float elapsed_time;
			Uint64 frame_time;
			Uint64 frame_start;
			Uint64 frame_count;
			Uint64 previous_tick = SDL_GetPerformanceCounter();
			Uint64 fps_timer = previous_tick;

		public:
			TimeManager();

			~TimeManager();

			float get_fps();

			void calculate_fps();

			float get_delta_time();

			void calculate_delta_time(const unsigned int&);
	};
}

#endif

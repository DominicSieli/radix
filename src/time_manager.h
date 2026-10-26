#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SDL3/SDL.h>

namespace Radix
{
	class TimeManager
	{
		private:
			float fps;
			bool paused;
			float delta_time;
			float elapsed_time;
			Uint64 frame_count;
			Uint64 fps_timer = SDL_GetPerformanceCounter();
			Uint64 previous_tick = SDL_GetPerformanceCounter();

		public:
			TimeManager();

			~TimeManager();

			float get_fps();

			void pause();

			void unpause();

			bool is_paused();

			void calculate_fps();

			float get_delta_time();

			void calculate_delta_time(const float&);
	};
}

#endif

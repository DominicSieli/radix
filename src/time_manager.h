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
			Uint64 frameTime;
			Uint64 frameStart;
			Uint64 previous_tick;

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

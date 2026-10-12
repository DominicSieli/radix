#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SDL3/SDL.h>

namespace Radix
{
	class TimeManager
	{
		private:
			float delta_time;

		public:
			TimeManager();

			~TimeManager();

			float get_delta_time();

			void update_delta_time(const unsigned int&);
	};
}

#endif

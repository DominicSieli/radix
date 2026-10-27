#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

namespace Radix
{
	class StateManager
	{
		private:
			bool paused = false;
			bool running = true;

		public:
			StateManager();

			~StateManager();

			void pause();

			void unpause();

			bool is_paused();

			bool is_running();

			void exit_game();
	};
}

#endif

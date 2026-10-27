#include "state_manager.h"

namespace Radix
{
	StateManager::StateManager()
	{}

	StateManager::~StateManager()
	{}

	void StateManager::pause()
	{
		paused = true;
	}

	void StateManager::unpause()
	{
		paused = false;
	}

	bool StateManager::is_paused()
	{
		return paused;
	}

	bool StateManager::is_running()
	{
		return running;
	}

	void StateManager::exit_game()
	{
		running = false;
	}
}

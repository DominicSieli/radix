#include "game.h"
#include "entity.h"
#include "render_manager.h"

namespace Radix
{
	RenderManager::RenderManager()
	{}

	RenderManager::~RenderManager()
	{
		destroy();
	}

	bool RenderManager::initialize(SDL_Window* window, const char* graphics_api)
	{
		renderer = SDL_CreateRenderer(window, graphics_api);

		if(renderer == nullptr)
		{
			SDL_Log("Error Creating SDL Renderer");

			return false;
		}

		return true;
	}

	SDL_Renderer* RenderManager::get_renderer()
	{
		return renderer;
	}

	void RenderManager::render(const unsigned int& layer_count)
	{
		for(unsigned int i = 0; i < layer_count; ++i)
		{
			for(Entity* entity : Game::entity_manager.get_entities_by_render_layer(i))
			{
				if(entity->is_active())
				{
					entity->render();
				}
			}
		}
	}

	void RenderManager::destroy()
	{
		SDL_DestroyRenderer(renderer);
	}
}
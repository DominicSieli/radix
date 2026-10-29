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

	bool RenderManager::initialize(SDL_Window* window, const char* graphics_api, const int& vsync)
	{
		renderer = SDL_CreateRenderer(window, graphics_api);
		SDL_SetRenderVSync(renderer, vsync);

		if(renderer == nullptr)
		{
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
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

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

		SDL_RenderPresent(renderer);
	}

	void RenderManager::destroy()
	{
		SDL_DestroyRenderer(renderer);
	}
}
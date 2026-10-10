#include "game.h"
#include "entity.h"
#include "render_manager.h"

namespace Radix
{
	RenderManager::RenderManager()
	{}

	void RenderManager::render(const unsigned int& layer_count)
	{
		for(unsigned int i = 0; i < layer_count; i++)
		{
			for(Entity* entity : Game::entity_manager.get_entities_by_render_layer(i))
			{
				entity->render();
			}
		}
	}
}
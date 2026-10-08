#include "game.h"
#include "entity.h"
#include "render_manager.h"

namespace Radix
{
	RenderManager::RenderManager()
	{}

	RenderManager::~RenderManager()
	{}

	void RenderManager::render(const unsigned int& layer_count)
	{
		for(unsigned int layer_number = 0; layer_number < layer_count; layer_number++)
		{
			for(Entity* entity : Game::entity_manager.get_entities_by_render_layer(layer_number))
			{
				entity->render();
			}
		}
	}
}
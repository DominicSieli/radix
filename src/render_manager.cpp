#include "game.h"
#include "entity.h"
#include "render_manager.h"

namespace Radix
{
	RenderManager::RenderManager(const unsigned int layer_count)
		: layer_count{layer_count}
	{}

	RenderManager::~RenderManager()
	{}

	unsigned int RenderManager::get_layer_count()
	{
		return this->layer_count;
	}

	void RenderManager::render()
	{
		for(unsigned int layer_number = 0; layer_number < this->layer_count; layer_number++)
		{
			for(Entity* entity : Game::entity_manager->get_entities_by_render_layer(layer_number))
			{
				entity->render();
			}
		}
	}
}
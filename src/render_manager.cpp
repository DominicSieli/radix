#include "game.h"
#include "entity.h"
#include "render_manager.h"

namespace Radix
{
	RenderManager::RenderManager()
	{}

	void RenderManager::render()
	{
		for(int layer_number = 0; layer_number < 10; layer_number++)
		{
			for(Entity* entity: Game::entity_manager.get_entities_by_layer(layer_number))
			{
				entity->render();
			}
		}
	}
}
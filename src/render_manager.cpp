#include "entity.h"
#include "render_manager.h"
#include "entity_manager.h"

namespace Radix
{
	RenderManager::RenderManager()
	{}

	RenderManager::RenderManager(EntityManager* entity_manager)
		: entity_manager{entity_manager}
	{}

	void RenderManager::render()
	{
		for(int layer_number = 0; layer_number < 10; layer_number++)
		{
			for(Entity* entity: this->entity_manager->get_entities_by_layer(static_cast<unsigned int>(layer_number)))
			{
				entity->render();
			}
		}
	}
}
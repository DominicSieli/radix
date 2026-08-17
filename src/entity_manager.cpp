#include <iostream>

#include "collision.h"
#include "entity_manager.h"
#include "collider_component.h"

namespace radix
{
	void EntityManager::clear()
	{
		for(auto& entity : entities)
		{
			entity->destroy();
		}
	}

	void EntityManager::update(float delta_time)
	{
		for(auto& entity : entities)
		{
			entity->update(delta_time);
		}

		destroy_inactive_entities();
	}

	void EntityManager::destroy_inactive_entities()
	{
		for(int i = 0; i < entities.size(); i++)
		{
			if(entities[i]->is_active() == false)
			{
				entities.erase(entities.begin() + i);
			}
		}
	}

	void EntityManager::render()
	{
		for(int layer_number = 0; layer_number < LAYER_COUNT; layer_number++)
		{
			for(auto& entity: get_entities_by_layer(static_cast<LayerType>(layer_number)))
			{
				entity->render();
			}
		}
	}

	bool EntityManager::is_empty() const
	{
		return entities.size() == 0;
	}

	void EntityManager::list_entities() const
	{
		for(unsigned int i = 0; i < entities.size(); i++)
		{
			std::cout << "Entity[" << i << "]: " << entities[i]->name << "\n";
			entities[i]->list_components();
		}
	}

	Entity& EntityManager::add_entity(std::string name, LayerType layer)
	{
		Entity* entity = new Entity(*this, name, layer);
		entities.emplace_back(entity);
		return *entity;
	}

	std::vector<Entity*> EntityManager::get_entities() const
	{
		return entities;
	}

	std::vector<Entity*> EntityManager::get_entities_by_layer(LayerType layer) const
	{
		std::vector<Entity*> selected_entities;

		for(auto& entity: entities)
		{
			if(entity->layer == layer) selected_entities.emplace_back(entity);
		}

		return selected_entities;
	}

	CollisionType EntityManager::check_collisions() const
	{
		for(int i = 0; i < entities.size() - 1; i++)
		{
			auto& this_entity = entities[i];

			if(this_entity->has_component<ColliderComponent>() == true)
			{
				ColliderComponent* this_collider = this_entity->get_component<ColliderComponent>();

				for(int j = i + 1; j < entities.size(); j++)
				{
					auto& that_entity = entities[j];

					if(this_entity->name.compare(that_entity->name) != 0 && that_entity->has_component<ColliderComponent>() == true)
					{
						ColliderComponent* that_collider = that_entity->get_component<ColliderComponent>();

						if(Collision::check_rectangle_collision(this_collider->collider, that_collider->collider) == true)
						{
							if(this_collider->tag.compare("PLAYER") == 0 && that_collider->tag.compare("ENEMY") == 0)
							{
								return PLAYER_ENEMY_COLLISION;
							}

							if(this_collider->tag.compare("PLAYER") == 0 && that_collider->tag.compare("PROJECTILE") == 0)
							{
								return PLAYER_PROJECTILE_COLLISION;
							}

							if(this_collider->tag.compare("ENEMY") == 0 && that_collider->tag.compare("PLAYER_PROJECTILE") == 0)
							{
								return ENEMY_PROJECTILE_COLLISION;
							}

							if(this_collider->tag.compare("PLAYER") == 0 && that_collider->tag.compare("LEVEL_COMPLETE") == 0)
							{
								return PLAYER_LEVEL_COMPLETE_COLLISION;
							}
						}
					}
				}
			}
		}

		return NO_COLLISION;
	}

	unsigned int EntityManager::entity_count()
	{
		return entities.size();
	}
}
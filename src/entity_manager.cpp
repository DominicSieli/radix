#include <iostream>

#include "collision.h"
#include "entity_manager.h"
#include "collider_component.h"

namespace Radix
{
	EntityManager::EntityManager()
	{}

	void EntityManager::clear()
	{
		for(auto* entity : entities)
		{
			entity->destroy();
		}
	}

	void EntityManager::update(float delta_time)
	{
		for(auto* entity : entities)
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
		for(int layer_number = 0; layer_number < 10; layer_number++)
		{
			for(auto* entity: get_entities_by_layer(static_cast<unsigned int>(layer_number)))
			{
				entity->render();
			}
		}
	}

	bool EntityManager::is_empty() const
	{
		return entities.size() == 0;
	}

	Entity* EntityManager::add_entity(std::string name, const unsigned int& render_layer)
	{
		Entity* entity = new Entity(this, name, render_layer);
		entities.emplace_back(entity);
		return entity;
	}

	std::vector<Entity*> EntityManager::get_entities() const
	{
		return entities;
	}

	std::vector<Entity*> EntityManager::get_entities_by_layer(const unsigned int& render_layer) const
	{
		std::vector<Entity*> selected_entities;

		for(auto* entity: entities)
		{
			if(entity->render_layer == render_layer) selected_entities.emplace_back(entity);
		}

		return selected_entities;
	}

	Collisions EntityManager::check_collisions() const
	{
		for(int i = 0; i < entities.size() - 1; i++)
		{
			auto* this_entity = entities[i];

			if(this_entity->has_component<ColliderComponent>() == true)
			{
				ColliderComponent* this_collider = this_entity->get_component<ColliderComponent>();

				for(int j = i + 1; j < entities.size(); j++)
				{
					auto* that_entity = entities[j];

					if(this_entity->name.compare(that_entity->name) != 0 && that_entity->has_component<ColliderComponent>() == true)
					{
						ColliderComponent* that_collider = that_entity->get_component<ColliderComponent>();

						if(check_rect_collision(this_collider->collider, that_collider->collider) == true)
						{
							if(this_collider->tag == PLAYER_COLLIDER && that_collider->tag == ENEMY_COLLIDER)
							{
								return PLAYER_ENEMY_COLLISION;
							}

							if(this_collider->tag == PLAYER_COLLIDER && that_collider->tag == ENEMY_PROJECTILE_COLLIDER)
							{
								return PLAYER_PROJECTILE_COLLISION;
							}

							if(this_collider->tag == ENEMY_COLLIDER && that_collider->tag == PLAYER_PROJECTILE_COLLIDER)
							{
								return ENEMY_PROJECTILE_COLLISION;
							}

							if(this_collider->tag == PLAYER_COLLIDER && that_collider->tag == LEVEL_COMPLETE_COLLIDER)
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
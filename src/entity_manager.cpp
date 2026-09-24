#include "game.h"
#include "entity_manager.h"

namespace Radix
{
	EntityManager::EntityManager()
	{}

	EntityManager::~EntityManager()
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

	bool EntityManager::is_empty()
	{
		return entities.size() == 0;
	}

	Entity* EntityManager::add_entity(std::string name, unsigned int render_layer)
	{
		Entity* entity = new Entity(this, name, render_layer);
		entities.emplace_back(entity);
		return entity;
	}

	std::vector<Entity*> EntityManager::get_entities()
	{
		return entities;
	}

	std::vector<Entity*> EntityManager::get_entities_by_layer(unsigned int render_layer)
	{
		std::vector<Entity*> selected_entities;

		for(auto* entity: entities)
		{
			if(entity->render_layer == render_layer) selected_entities.emplace_back(entity);
		}

		return selected_entities;
	}

	unsigned int EntityManager::entity_count()
	{
		return entities.size();
	}
}
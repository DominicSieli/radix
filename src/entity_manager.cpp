#include "game.h"
#include "entity.h"
#include "entity_manager.h"

namespace Radix
{
	EntityManager::EntityManager()
	{}

	EntityManager::~EntityManager()
	{
		this->clear_entities();
	}

	void EntityManager::clear_entities()
	{
		this->entities.clear();
	}

	void EntityManager::update(float delta_time)
	{
		for(Entity* entity : entities)
		{
			entity->update(delta_time);
		}
	}

	void EntityManager::destroy_inactive_entities()
	{
		for(Entity* entity : entities)
		{
			if(entity->is_active() == false)
			{
				delete entity;
			}
		}
	}

	bool EntityManager::is_empty()
	{
		return entities.size() == 0;
	}

	Entity* EntityManager::add_entity(const std::string& name, const unsigned int& render_layer)
	{
		Entity* entity = new Entity(name, render_layer);
		entities.emplace_back(entity);

		return entity;
	}

	Entity* EntityManager::get_entity_by_id(unsigned int id)
	{
		for(Entity* entity : entities)
		{
			if(entity->get_id() == id)
			{
				return entity;
			}
		}

		return nullptr;
	}

	std::vector<Entity*> EntityManager::get_entities()
	{
		return entities;
	}

	std::vector<Entity*> EntityManager::get_entities_by_render_layer(unsigned int render_layer)
	{
		std::vector<Entity*> selected_entities;

		for(auto* entity: entities)
		{
			if(entity->get_render_layer() == render_layer) selected_entities.emplace_back(entity);
		}

		return selected_entities;
	}

	unsigned int EntityManager::entity_count()
	{
		return entities.size();
	}
}
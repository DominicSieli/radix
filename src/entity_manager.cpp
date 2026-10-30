#include "entity.h"
#include "entity_manager.h"

namespace Radix
{
	EntityManager::EntityManager()
	{}

	EntityManager::~EntityManager()
	{
		delete_entities();
	}

	void EntityManager::delete_entities()
	{
		for(auto* entity : entities)
		{
			delete entity;
			entity = nullptr;
		}

		entities.clear();
	}

	void EntityManager::update(const float& delta_time)
	{
		for(Entity* entity : entities)
		{
			if(entity->is_active())
			{
				entity->update(delta_time);
			}
		}
	}

	void EntityManager::delete_inactive_entities()
	{
		for(unsigned int i = 0; i < entities.size(); ++i)
		{
			if(!entities.at(i)->is_active())
			{
				delete entities.at(i);
				entities.at(i) = nullptr;
			}
		}
	}

	bool EntityManager::is_empty()
	{
		return entities.size() == 0;
	}

	Entity* EntityManager::create_entity(const unsigned int& type_id, const unsigned int& render_layer)
	{
		for(unsigned int i = 0; i < entities.size(); ++i)
		{
			if(entities.at(i) != nullptr)
			{
				if(entities.at(i)->get_type_id() == type_id)
				{
					if(!entities.at(i)->is_active())
					{
						entities.at(i)->set_active();

						return entities.at(i);
					}
				}
			}

			if(entities.at(i) == nullptr)
			{
				Entity* entity = new Entity(type_id, render_layer);
				entities.at(i) = entity;

				return entity;
			}
		}

		Entity* entity = new Entity(type_id, render_layer);
		entities.emplace_back(entity);

		return entity;
	}

	Entity* EntityManager::get_entity_by_id(const unsigned int& id)
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

	bool EntityManager::delete_entity_by_id(const unsigned int& id)
	{
		for(unsigned int i = 0; i < entities.size(); ++i)
		{
			if(entities.at(i)->get_id() == id)
			{
				delete entities.at(i);
				entities.at(i) = nullptr;

				return true;
			}
		}

		return false;
	}

	void EntityManager::delete_entities_by_type_id(const unsigned int& type_id)
	{
		for(unsigned int i = 0; i < entities.size(); ++i)
		{
			if(entities.at(i)->get_type_id() == type_id)
			{
				delete entities.at(i);
				entities.at(i) = nullptr;
			}
		}
	}

	std::vector<Entity*> EntityManager::get_entities()
	{
		return entities;
	}


	std::vector<Entity*> EntityManager::get_entities_by_type_id(const unsigned int& type_id)
	{
		std::vector<Entity*> selected_entities;

		for(Entity* entity : entities)
		{
			if(entity->get_type_id() == type_id)
			{
				selected_entities.emplace_back(entity);
			}
		}

		return selected_entities;
	}

	std::vector<Entity*> EntityManager::get_entities_by_render_layer(const unsigned int& render_layer)
	{
		std::vector<Entity*> selected_entities;

		for(Entity* entity : entities)
		{
			if(entity->get_render_layer() == render_layer)
			{
				selected_entities.emplace_back(entity);
			}
		}

		return selected_entities;
	}

	unsigned int EntityManager::entity_count()
	{
		return entities.size();
	}
}
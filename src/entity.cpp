#include <iostream>

#include "entity.h"

namespace Radix
{
	Entity::Entity(EntityManager* entity_manager)
	{
		this->active = true;
		this->entity_manager = entity_manager;
	}

	Entity::Entity(EntityManager* entity_manager, std::string name, const unsigned int& render_layer)
		: entity_manager{entity_manager}, name{name}, render_layer{render_layer}
	{
		this->active = true;
	}

	void Entity::update(float delta_time)
	{
		for(auto& component : components)
		{
			component->update(delta_time);
		}
	}

	void Entity::render()
	{
		for(auto& component : components)
		{
			component->render();
		}
	}

	void Entity::destroy()
	{
		this->active = false;
	}

	bool Entity::is_active() const
	{
		return this->active;
	}
}
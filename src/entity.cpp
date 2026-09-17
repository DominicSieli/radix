#include <iostream>

#include "entity.h"

namespace Radix
{
	Entity::Entity(EntityManager* entity_manager)
	{
		this->active = true;
		this->entity_manager = entity_manager;
	}

	Entity::Entity(EntityManager* entity_manager, std::string name, LayerType layer_type)
	{
		this->name = name;
		this->active = true;
		this->layer_type = layer_type;
		this->entity_manager = entity_manager;
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
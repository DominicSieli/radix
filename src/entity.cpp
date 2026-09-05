#include <iostream>

#include "entity.h"

namespace radix
{
	Entity::Entity(EntityManager& entity_manager): entity_manager{entity_manager}
	{
		this->active = true;
	}

	Entity::Entity(EntityManager& entity_manager, std::string name, LayerType layer_type): entity_manager{entity_manager}, name{name}, layer_type{layer_type}
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

	void Entity::list_components() const
	{
		for(auto component: component_type_map)
		{
			std::cout << "Component<" << component.first->name() << ">" << "\n";
		}
	}
}
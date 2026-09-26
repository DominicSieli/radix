#include "entity.h"

namespace Radix
{
	Entity::Entity()
	{
		this->active = true;
	}

	Entity::Entity(std::string name, unsigned int render_layer)
		: name{name}, render_layer{render_layer}
	{
		this->active = true;
	}

	Entity::~Entity()
	{}

	void Entity::update(double delta_time)
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

	bool Entity::is_active()
	{
		return this->active;
	}
}
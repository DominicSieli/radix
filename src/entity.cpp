#include "entity.h"

namespace Radix
{
	Entity::Entity()
	{}

	Entity::Entity(const std::string& name, const unsigned int& render_layer):
		active{true}, id{current_id++}, name{name}, render_layer{render_layer}
	{}

	Entity::~Entity()
	{
		this->clear_components();
	}

	void Entity::update(const float& delta_time)
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

	void Entity::deactivate()
	{
		this->active = false;
	}

	bool Entity::is_active()
	{
		return this->active;
	}

	unsigned int Entity::get_id()
	{
		return this->id;
	}

	std::string Entity::get_name()
	{
		return this->name;
	}

	void Entity::clear_components()
	{
		components.clear();
	}

	unsigned int Entity::get_render_layer()
	{
		return this->render_layer;
	}
}
#include "entity.h"

namespace Radix
{
	Entity::Entity()
	{}

	Entity::Entity(const unsigned int& type_id, const unsigned int& render_layer):
		active{true}, id{current_id++}, type_id{type_id}, render_layer{render_layer}
	{}

	Entity::~Entity()
	{
		clear_components();
	}

	void Entity::update(const float& delta_time)
	{
		if(active)
		{
			for(const auto& component : components)
			{
				if(component->is_active())
				{
					component->update(delta_time);
				}
			}
		}
	}

	void Entity::render()
	{
		if(active)
		{
			for(const auto& component : components)
			{
				if(component->is_active())
				{
					component->render();
				}
			}
		}
	}

	bool Entity::is_active()
	{
		return active;
	}

	void Entity::set_active()
	{
		active = true;
	}

	void Entity::set_inactive()
	{
		active = false;
	}

	unsigned int Entity::get_id()
	{
		return id;
	}

	unsigned int Entity::get_type_id()
	{
		return type_id;
	}

	void Entity::clear_components()
	{
		for(auto* component : components)
		{
			delete component;
			component = nullptr;
		}

		for(auto& [key, component] : component_map)
		{
			delete component;
			component = nullptr;
		}

		components.clear();
		component_map.clear();
	}

	unsigned int Entity::get_render_layer()
	{
		return render_layer;
	}
}
#include "collider_component.h"

namespace radix
{
	ColliderComponent::ColliderComponent(std::string tag, int x, int y, int width, int height)
	{
		this->tag = tag;
		this->collider = {x, y, width, height};
	}

	void ColliderComponent::initialize()
	{
		if(entity->has_component<TransformComponent>())
		{
			transform_component = entity->get_component<TransformComponent>();
			source_rectangle = {0, 0, (int)transform_component->dimension.x, (int)transform_component->dimension.y};
			destination_rectangle = {collider.x, collider.y, collider.w, collider.h};
		}
	}

	void ColliderComponent::update(float delta_time)
	{
		collider.x = static_cast<int>(transform_component->position.x);
		collider.y = static_cast<int>(transform_component->position.y);
		collider.w = transform_component->dimension.x * transform_component->scale;
		collider.h = transform_component->dimension.y * transform_component->scale;
		destination_rectangle.x = collider.x - Game::camera.x;
		destination_rectangle.y = collider.y - Game::camera.y;
	}
}
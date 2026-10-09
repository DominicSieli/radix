#include "game.h"
#include "collider_component.h"

namespace Radix
{
	ColliderComponent::ColliderComponent(const unsigned int& tag, const Vector2<int>& dimensions):
		tag{tag}, dimensions{dimensions}
	{}

	void ColliderComponent::initialize()
	{
		if(entity->has_component<TransformComponent>())
		{
			transform_component = entity->get_component<TransformComponent>();
			source_rect = {0, 0, dimensions.x, dimensions.y};
			destination_rect = {collider.x, collider.y, collider.w, collider.h};
			collider = {static_cast<int>(transform_component->position.x), static_cast<int>(transform_component->position.y), dimensions.x, dimensions.y};
		}
	}

	void ColliderComponent::update(const float&)
	{
		collider.x = static_cast<int>(transform_component->position.x);
		collider.y = static_cast<int>(transform_component->position.y);
		collider.w = dimensions.x * static_cast<int>(transform_component->scale.x);
		collider.h = dimensions.y * static_cast<int>(transform_component->scale.y);
		destination_rect.x = collider.x - Game::camera.x;
		destination_rect.y = collider.y - Game::camera.y;
	}
}
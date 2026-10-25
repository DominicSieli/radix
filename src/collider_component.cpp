#include "game.h"
#include "collider_component.h"

namespace Radix
{
	ColliderComponent::ColliderComponent(const unsigned int& tag, const Vector2<float>& dimensions):
		tag{tag}, dimensions{dimensions}
	{}

	void ColliderComponent::initialize()
	{
		transform_component = get_entity()->get_component<TransformComponent>();
		Vector2<float> position = transform_component->get_position();

		source_rect = {0, 0, dimensions.x, dimensions.y};
		destination_rect = {collider.x, collider.y, collider.w, collider.h};
		collider = {position.x, position.y, dimensions.x, dimensions.y};
	}

	void ColliderComponent::update(const float&)
	{
		Vector2<float> scale = transform_component->get_scale();
		Vector2<float> position = transform_component->get_position();

		collider.x = position.x;
		collider.y = position.y;
		collider.w = dimensions.x * scale.x;
		collider.h = dimensions.y * scale.y;
		destination_rect.x = collider.x - Game::camera_manager.get_camera().x;
		destination_rect.y = collider.y - Game::camera_manager.get_camera().y;
	}

	unsigned int ColliderComponent::get_tag()
	{
		return tag;
	}

	SDL_FRect ColliderComponent::get_collider()
	{
		return collider;
	}
}
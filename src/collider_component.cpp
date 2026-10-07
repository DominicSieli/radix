#include "game.h"
#include "collider_component.h"

namespace Radix
{
	ColliderComponent::ColliderComponent()
	{}

	ColliderComponent::ColliderComponent(unsigned int tag, Vector2<int> dimensions)
		: tag{tag}, dimensions{dimensions}
	{}

	ColliderComponent::~ColliderComponent()
	{}

	void ColliderComponent::initialize()
	{
		if(this->entity->has_component<TransformComponent>())
		{
			this->transform_component = this->entity->get_component<TransformComponent>();
			this->source_rect = {0, 0, this->dimensions.x, this->dimensions.y};
			this->destination_rect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
			this->collider = {static_cast<int>(this->transform_component->position.x), static_cast<int>(this->transform_component->position.y), this->dimensions.x, this->dimensions.y};
		}
	}

	void ColliderComponent::update(float)
	{
		this->collider.x = static_cast<int>(this->transform_component->position.x);
		this->collider.y = static_cast<int>(this->transform_component->position.y);
		this->collider.w = this->dimensions.x * static_cast<int>(this->transform_component->scale.x);
		this->collider.h = this->dimensions.y * static_cast<int>(this->transform_component->scale.y);
		this->destination_rect.x = this->collider.x - Game::camera.x;
		this->destination_rect.y = this->collider.y - Game::camera.y;
	}
}
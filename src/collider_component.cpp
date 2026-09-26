#include "collider_component.h"

namespace Radix
{
	ColliderComponent::ColliderComponent()
	{}

	ColliderComponent::ColliderComponent(unsigned int tag, int x, int y, int w, int h)
		: tag{tag}
	{
		this->collider = {x, y, w, h};
	}

	ColliderComponent::~ColliderComponent()
	{}

	void ColliderComponent::initialize()
	{
		if(this->entity->has_component<TransformComponent>())
		{
			this->transform_component = this->entity->get_component<TransformComponent>();
			this->source_rect = {0, 0, (int)this->transform_component->dimensions.x, (int)this->transform_component->dimensions.y};
			this->destination_rect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
		}
	}

	void ColliderComponent::update(double delta_time)
	{
		this->collider.x = static_cast<int>(this->transform_component->position.x);
		this->collider.y = static_cast<int>(this->transform_component->position.y);
		this->collider.w = this->transform_component->dimensions.x * this->transform_component->scale.x;
		this->collider.h = this->transform_component->dimensions.y * this->transform_component->scale.y;
		this->destination_rect.x = this->collider.x - Game::camera.x;
		this->destination_rect.y = this->collider.y - Game::camera.y;
	}
}
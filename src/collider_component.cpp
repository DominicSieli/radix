#include "collider_component.h"

namespace Radix
{
	ColliderComponent::ColliderComponent(const unsigned int& tag, const int& x, const int& y, const int& w, const int& h)
		: tag{tag}
	{
		this->collider = {x, y, w, h};
	}

	void ColliderComponent::initialize()
	{
		if(this->entity->has_component<TransformComponent>())
		{
			this->transform_component = this->entity->get_component<TransformComponent>();
			this->source_rect = {0, 0, (int)this->transform_component->dimension.x, (int)this->transform_component->dimension.y};
			this->destination_rect = {this->collider.x, this->collider.y, this->collider.w, this->collider.h};
		}
	}

	void ColliderComponent::update(float delta_time)
	{
		this->collider.x = static_cast<int>(this->transform_component->position.x);
		this->collider.y = static_cast<int>(this->transform_component->position.y);
		this->collider.w = this->transform_component->dimension.x * this->transform_component->scale;
		this->collider.h = this->transform_component->dimension.y * this->transform_component->scale;
		this->destination_rect.x = this->collider.x - Game::camera.x;
		this->destination_rect.y = this->collider.y - Game::camera.y;
	}
}
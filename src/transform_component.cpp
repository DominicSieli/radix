#include "transform_component.h"

namespace radix
{
	TransformComponent::TransformComponent(int position_x, int position_y, int velocity_x, int velocity_y, int dimension_x, int dimension_y, int scale)
	{
		this->scale = scale;
		this->position = glm::vec2(position_x, position_y);
		this->velocity = glm::vec2(velocity_x, velocity_y);
		this->dimension = glm::vec2(dimension_x, dimension_y);
	}

	void TransformComponent::initialize()
	{}

	void TransformComponent::update(float delta_time)
	{
		position.x += velocity.x * delta_time;
		position.y += velocity.y * delta_time;
	}

	void TransformComponent::render()
	{}
}
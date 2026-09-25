#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent()
	{}

	TransformComponent::~TransformComponent()
	{}

	TransformComponent::TransformComponent(int position_x, int position_y, int velocity_x, int velocity_y, int dimension_x, int dimension_y, int scale)
	{
		this->scale = scale;
		this->position = Point2D(position_x, position_y);
		this->velocity = Point2D(velocity_x, velocity_y);
		this->dimension = Point2D(dimension_x, dimension_y);
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
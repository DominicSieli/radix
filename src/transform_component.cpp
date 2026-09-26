#include "cmath"

#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent()
	{}

	TransformComponent::~TransformComponent()
	{}

	TransformComponent::TransformComponent(Vector2<unsigned int> position, Vector2<unsigned int> dimensions, Vector2<double> scale, double rotation)
		: position{position}, dimensions{dimensions}, scale{scale}, rotation{rotation}
	{}

	void TransformComponent::initialize()
	{}

	void TransformComponent::update(double delta_time)
	{}

	void TransformComponent::render()
	{}


	void TransformComponent::rotate(double degree)
	{
		//this->rotation = degree * std::numbers::pi_v<double> / 180.0;
	}

	void TransformComponent::rescale(Vector2<double> factors)
	{}

	void TransformComponent::translate(Vector2<unsigned int> velocity)
	{
		this->position.x += velocity.x;
		this->position.y += velocity.y;

		//velocity = Vector2(std::cos(radian) * speed, std::sin(radian) * speed);
	}
}
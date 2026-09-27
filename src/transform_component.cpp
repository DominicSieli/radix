#include "cmath"

#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent()
	{}

	TransformComponent::~TransformComponent()
	{}

	TransformComponent::TransformComponent(Vector2<double> position, Vector2<float> scale, float rotation)
		: position{position}, scale{scale}, rotation{rotation}
	{}

	void TransformComponent::initialize()
	{}

	void TransformComponent::update(float delta_time)
	{}

	void TransformComponent::render()
	{}


	void TransformComponent::rotate(float degree)
	{
		//this->rotation = degree * std::numbers::pi_v<float> / 180.0;
	}

	void TransformComponent::rescale(Vector2<float> factors)
	{}

	void TransformComponent::translate(Vector2<double> velocity)
	{
		this->position.x += velocity.x * Game::delta_time;
		this->position.y += velocity.y * Game::delta_time;

		//velocity = Vector2(std::cos(radian) * speed, std::sin(radian) * speed);
	}
}
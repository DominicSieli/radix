#include "cmath"

#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent()
	{}

	TransformComponent::TransformComponent(const Vector2<float>& position, const Vector2<float>& scale, const float& rotation):
		position{position},
		scale{scale},
		rotation{rotation}
	{}

	TransformComponent::~TransformComponent()
	{}

	void TransformComponent::initialize()
	{}

	void TransformComponent::update(float)
	{}

	void TransformComponent::render()
	{}

	void TransformComponent::rotate(const float& degree)
	{
		this->rotation += degree * Game::delta_time;
	}

	void TransformComponent::set_rotation(const float& degree)
	{
		this->rotation = degree;
	}

	void TransformComponent::rescale(const Vector2<float>& factors)
	{
		this->scale.x *= factors.x;
		this->scale.y *= factors.y;
	}

	void TransformComponent::translate(const Vector2<float>& speed)
	{
		this->position.x += speed.x * Game::delta_time;
		this->position.y += speed.y * Game::delta_time;

		//velocity = Vector2(std::cos(radian) * speed, std::sin(radian) * speed);
	}
}
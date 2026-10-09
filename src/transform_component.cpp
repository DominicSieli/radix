#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent(const Vector2<float>& position, const Vector2<float>& scale, const float& rotation):
		position{position}, scale{scale}, rotation{rotation}
	{}

	void TransformComponent::rotate(const float& degree)
	{
		this->rotation += degree * Game::delta_time;
	}

	void TransformComponent::set_rotation(const float& degree)
	{
		this->rotation = degree;
	}

	void TransformComponent::scaling(const Vector2<float>& factor)
	{
		this->scale.x *= factor.x;
		this->scale.y *= factor.y;
	}

	void TransformComponent::set_scale(const Vector2<float>& scale)
	{
		this->scale.x = scale.x;
		this->scale.y = scale.y;
	}

	void TransformComponent::translate(const Vector2<float>& speed)
	{
		this->position.x += speed.x * Game::delta_time;
		this->position.y += speed.y * Game::delta_time;
	}

	void TransformComponent::set_position(const Vector2<float>& position)
	{
		this->position.x = position.x;
		this->position.y = position.y;
	}
}
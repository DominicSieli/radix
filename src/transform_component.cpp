#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent(const Vector2<float>& position, const Vector2<float>& scale, const float& rotation):
		position{position}, scale{scale}, rotation{rotation}
	{}

	void TransformComponent::rotate(const float& degree)
	{
		rotation += degree * Game::delta_time;
	}

	void TransformComponent::set_rotation(const float& new_rotation)
	{
		rotation = new_rotation;
	}

	void TransformComponent::scaling(const Vector2<float>& factor)
	{
		scale.x *= factor.x * Game::delta_time;
		scale.y *= factor.y * Game::delta_time;
	}

	void TransformComponent::set_scale(const Vector2<float>& new_scale)
	{
		scale.x = new_scale.x;
		scale.y = new_scale.y;
	}

	void TransformComponent::translate(const Vector2<float>& speed)
	{
		position.x += speed.x * Game::delta_time;
		position.y += speed.y * Game::delta_time;
	}

	void TransformComponent::set_position(const Vector2<float>& new_position)
	{
		position.x = new_position.x;
		position.y = new_position.y;
	}
}
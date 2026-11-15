#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent(const Vector2<float>& dimensions, const Vector2<float>& position, const Vector2<float>& scale, const float& rotation):
		rotation{rotation}, scale{scale}, position{position}, dimensions{dimensions}
	{}

	void TransformComponent::rotate(const float& degree)
	{
		float delta_time = Game::time_manager.get_delta_time();

		rotation += degree * delta_time;
	}

	float TransformComponent::get_rotation()
	{
		return rotation;
	}

	void TransformComponent::set_rotation(const float& new_rotation)
	{
		rotation = new_rotation;
	}

	void TransformComponent::scaling(const Vector2<float>& value)
	{
		float delta_time = Game::time_manager.get_delta_time();

		scale.x += value.x * delta_time;
		scale.y += value.y * delta_time;
	}

	Vector2<float> TransformComponent::get_scale()
	{
		return scale;
	}

	void TransformComponent::set_scale(const Vector2<float>& new_scale)
	{
		scale.x = new_scale.x;
		scale.y = new_scale.y;
	}

	void TransformComponent::translate(const Vector2<float>& speed)
	{
		float delta_time = Game::time_manager.get_delta_time();

		position.x += speed.x * delta_time;
		position.y += speed.y * delta_time;
	}

	Vector2<float> TransformComponent::get_position()
	{
		return position;
	}

	void TransformComponent::set_position(const Vector2<float>& new_position)
	{
		position.x = new_position.x;
		position.y = new_position.y;
	}

	Vector2<float> TransformComponent::get_dimensions()
	{
		return dimensions;
	}

	void TransformComponent::set_dimensions(const Vector2<float>& new_dimensions)
	{
		dimensions.x = new_dimensions.x;
		dimensions.y = new_dimensions.y;
	}
}
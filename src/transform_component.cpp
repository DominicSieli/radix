#include "game.h"
#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent(const Vector2<float>& dimensions, const Vector2<float>& position, const Vector2<float>& scale, const float& rotation):
		rotation{rotation}, scale{scale}, position{position}, dimensions{dimensions}
	{}

	void TransformComponent::pause()
	{
		paused = true;
	}

	void TransformComponent::unpause()
	{
		paused = false;
	}

	bool TransformComponent::is_paused()
	{
		return paused;
	}

	void TransformComponent::rotate(const float& degree)
	{
		if(!paused)
		{
			rotation += degree * Game::time_manager.get_delta_time();
		}
	}

	float TransformComponent::get_rotation()
	{
		return rotation;
	}

	void TransformComponent::set_rotation(const float& new_rotation)
	{
		if(!paused)
		{
			rotation = new_rotation;
		}
	}

	void TransformComponent::scaling(const Vector2<float>& value)
	{
		if(!paused)
		{
			scale.x += value.x * Game::time_manager.get_delta_time();
			scale.y += value.y * Game::time_manager.get_delta_time();
		}
	}

	Vector2<float> TransformComponent::get_scale()
	{
		return scale;
	}

	void TransformComponent::set_scale(const Vector2<float>& new_scale)
	{
		if(!paused)
		{
			scale.x = new_scale.x;
			scale.y = new_scale.y;
		}
	}

	void TransformComponent::translate(const Vector2<float>& speed)
	{
		if(!paused)
		{
			position.x += speed.x * Game::time_manager.get_delta_time();
			position.y += speed.y * Game::time_manager.get_delta_time();
		}
	}

	Vector2<float> TransformComponent::get_position()
	{
		return position;
	}

	void TransformComponent::set_position(const Vector2<float>& new_position)
	{
		if(!paused)
		{
			position.x = new_position.x;
			position.y = new_position.y;
		}
	}

	Vector2<float> TransformComponent::get_dimensions()
	{
		return dimensions;
	}

	void TransformComponent::set_dimensions(const Vector2<float>& new_dimensions)
	{
		if(!paused)
		{
			dimensions.x = new_dimensions.x;
			dimensions.y = new_dimensions.y;
		}
	}
}
#include "game.h"
#include "constraints.h"
#include "transform_component.h"

namespace Radix
{
	bool inside_camera_bounds(const Vector2<float>& position, const Vector2<float>& dimensions)
	{
		float camera_x = static_cast<float>(Game::camera.x);
		float camera_y = static_cast<float>(Game::camera.y);
		float camera_w = static_cast<float>(Game::camera.w);
		float camera_h = static_cast<float>(Game::camera.h);

		if((position.x + (dimensions.x * 2.00f)) >= camera_x && (position.y + (dimensions.y * 2.00f)) >= camera_y && position.x <= (camera_x + camera_w) && position.y <= (camera_y + camera_h))
		{
			return true;
		}

		return false;
	}

	void constrain_to_camera_bounds(Entity* entity)
	{
		TransformComponent* transform_component = entity->get_component<TransformComponent>();

		float camera_x = static_cast<float>(Game::camera.x);
		float camera_y = static_cast<float>(Game::camera.y);
		float camera_w = static_cast<float>(Game::camera.w);
		float camera_h = static_cast<float>(Game::camera.h);
		float position_x = transform_component->get_position().x;
		float position_y = transform_component->get_position().y;
		float dimension_x = static_cast<float>(transform_component->get_dimensions().x);
		float dimension_y = static_cast<float>(transform_component->get_dimensions().y);

		if(position_x < camera_x)
		{
			transform_component->set_position(Vector2<float>(camera_x, position_y));
		}

		if(position_y < camera_y)
		{
			transform_component->set_position(Vector2<float>(position_x, camera_y));
		}

		if(position_x + dimension_x > camera_x + camera_w)
		{
			transform_component->set_position(Vector2<float>((camera_x + camera_w) - dimension_x, position_y));
		}

		if(position_y + dimension_y > camera_y + camera_h)
		{
			transform_component->set_position(Vector2<float>(position_x, (camera_y + camera_h) - dimension_y));
		}
	}
}

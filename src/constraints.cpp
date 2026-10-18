#include "game.h"
#include "constraints.h"
#include "transform_component.h"

namespace Radix
{
	bool inside_camera_bounds(const Vector2<float>& position, const Vector2<float>& dimensions)
	{
		if(position.x + (dimensions.x * 2) >= Game::camera.x && position.y + (dimensions.y * 2) >= Game::camera.y && position.x - dimensions.x <= Game::camera.x + Game::camera.w && position.y - dimensions.y <= Game::camera.y + Game::camera.h)
		{
			return true;
		}

		return false;
	}

	void constrain_to_camera_bounds(Entity* entity)
	{
		TransformComponent* transform_component = entity->get_component<TransformComponent>();

		Vector2<float> position = transform_component->get_position();
		Vector2<float> dimension = transform_component->get_dimensions();

		if(position.x < Game::camera.x)
		{
			transform_component->set_position(Vector2<float>(Game::camera.x, position.y));
		}

		if(position.y < Game::camera.y)
		{
			transform_component->set_position(Vector2<float>(position.x, Game::camera.y));
		}

		if(position.x + dimension.x > Game::camera.x + Game::camera.w)
		{
			transform_component->set_position(Vector2<float>((Game::camera.x + Game::camera.w) - dimension.x, position.y));
		}

		if(position.y + dimension.y > Game::camera.y + Game::camera.h)
		{
			transform_component->set_position(Vector2<float>(position.x, (Game::camera.y + Game::camera.h) - dimension.y));
		}
	}
}

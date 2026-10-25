#include "game.h"
#include "constraints.h"
#include "transform_component.h"

namespace Radix
{
	void constrain_to_camera_bounds(Entity* entity)
	{
		TransformComponent* transform_component = entity->get_component<TransformComponent>();

		Vector2<float> position = transform_component->get_position();
		Vector2<float> dimension = transform_component->get_dimensions();

		if(position.x < Game::camera_manager.get_camera().x)
		{
			transform_component->set_position(Vector2<float>(Game::camera_manager.get_camera().x, position.y));
		}

		if(position.y < Game::camera_manager.get_camera().y)
		{
			transform_component->set_position(Vector2<float>(position.x, Game::camera_manager.get_camera().y));
		}

		if(position.x + dimension.x > Game::camera_manager.get_camera().x + Game::camera_manager.get_camera().w)
		{
			transform_component->set_position(Vector2<float>((Game::camera_manager.get_camera().x + Game::camera_manager.get_camera().w) - dimension.x, position.y));
		}

		if(position.y + dimension.y > Game::camera_manager.get_camera().y + Game::camera_manager.get_camera().h)
		{
			transform_component->set_position(Vector2<float>(position.x, (Game::camera_manager.get_camera().y + Game::camera_manager.get_camera().h) - dimension.y));
		}
	}
}

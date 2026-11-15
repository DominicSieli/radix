#include "game.h"
#include "constraints.h"
#include "transform_component.h"

namespace Radix
{
	void constrain_to_camera_bounds(Entity* entity)
	{
		TransformComponent* transform_component = nullptr;

		if(entity->has_component<TransformComponent>())
		{
			transform_component = entity->get_component<TransformComponent>();
		}

		if(transform_component)
		{
			SDL_FRect camera = Game::camera_manager.get_camera();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimension = transform_component->get_dimensions();

			if(position.x < camera.x)
			{
				transform_component->set_position(Vector2<float>(camera.x, position.y));
			}

			if(position.y < camera.y)
			{
				transform_component->set_position(Vector2<float>(position.x, camera.y));
			}

			if(position.x + dimension.x > camera.x + camera.w)
			{
				transform_component->set_position(Vector2<float>((camera.x + camera.w) - dimension.x, position.y));
			}

			if(position.y + dimension.y > camera.y + camera.h)
			{
				transform_component->set_position(Vector2<float>(position.x, (camera.y + camera.h) - dimension.y));
			}
		}
	}
}

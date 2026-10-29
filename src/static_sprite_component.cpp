#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "vectors.h"
#include "asset_manager.h"
#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent(const bool& fixed, const SDL_FlipMode& flip, const unsigned int& texture_id):
		fixed{fixed}, flip{flip}, texture_id{texture_id}
	{}

	void StaticSpriteComponent::initialize()
	{
		set_texture(texture_id);
		renderer = Game::render_manager.get_renderer();
		transform_component = get_entity()->get_component<TransformComponent>();
	}

	void StaticSpriteComponent::update(const float&)
	{
		if(transform_component)
		{
			SDL_FRect camera = Game::camera_manager.get_camera();
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();

			source.x = 0;
			source.y = 0;
			source.w = dimensions.x;
			source.h = dimensions.y;

			destination.w = dimensions.x * scale.x;
			destination.h = dimensions.y * scale.y;
			destination.x = position.x - ((fixed == true) ? 0.00f : camera.x);
			destination.y = position.y - ((fixed == true) ? 0.00f : camera.y);
		}
	}

	void StaticSpriteComponent::render()
	{
		if(renderer && texture && transform_component)
		{
			float rotation = transform_component->get_rotation();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();
			bool is_inside_camera_bounds = Game::camera_manager.is_inside_bounds(position, dimensions);

			if(fixed || (!fixed && is_inside_camera_bounds))
			{
				SDL_RenderTextureRotated(renderer, texture, &source, &destination, rotation, nullptr, flip);
			}
		}
	}

	void StaticSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}
}
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "tile_component.h"

namespace Radix
{
	TileComponent::TileComponent(const unsigned int& texture_id, const SDL_FRect& source, const Vector2<float>& position, const float& scale):
		scale{scale}, source{source}, position{position}
	{
		set_texture(texture_id);
	}

	void TileComponent::initialize()
	{
		destination.x = position.x;
		destination.y = position.y;
		destination.w = source.w * scale;
		destination.h = source.h * scale;
	}

	void TileComponent::update(const float&)
	{
		SDL_FRect camera = Game::camera_manager.get_camera();

		destination.x = position.x - camera.x;
		destination.y = position.y - camera.y;
		destination.w = source.w * scale;
		destination.h = source.h * scale;
	}

	void TileComponent::render()
	{
		bool is_inside_camera_bounds = Game::camera_manager.is_inside_bounds(position, Vector2<float>(destination.w, destination.h));

		if(is_inside_camera_bounds)
		{
			SDL_Renderer* renderer = Game::render_manager.get_renderer();

			if(renderer && texture)
			{
				SDL_RenderTextureRotated(renderer, texture, &source, &destination, 0.00f, nullptr, SDL_FLIP_NONE);
			}
		}
	}

	void TileComponent::set_texture(const unsigned int& id)
	{
		texture = Game::texture_manager.get_texture(id);
	}
}
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "tile_component.h"

namespace Radix
{
	TileComponent::TileComponent(const Vector2<float>& rect_source, const Vector2<float>& rect_position, const int& tile_size, const float& tile_scale, const unsigned int& texture_id):
		texture{Game::asset_manager.get_texture(texture_id)}
	{
		source_rect.x = rect_source.x;
		source_rect.y = rect_source.y;
		source_rect.w = static_cast<float>(tile_size);
		source_rect.h = static_cast<float>(tile_size);

		destination_rect.x = rect_position.x;
		destination_rect.y = rect_position.y;
		destination_rect.w = static_cast<float>(tile_size) * tile_scale;
		destination_rect.h = static_cast<float>(tile_size) * tile_scale;

		position.x = rect_position.x;
		position.y = rect_position.y;
	}

	TileComponent::~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void TileComponent::update(const float&)
	{
		destination_rect.x = position.x - static_cast<float>(Game::camera_manager.get_camera().x);
		destination_rect.y = position.y - static_cast<float>(Game::camera_manager.get_camera().y);
	}

	void TileComponent::render()
	{
		if(Game::camera_manager.is_inside_bounds(position, Vector2<float>(destination_rect.w, destination_rect.h)))
		{
			SDL_Renderer* renderer = Game::render_manager.get_renderer();

			if(renderer && texture)
			{
				SDL_RenderTextureRotated(renderer, texture, &source_rect, &destination_rect, 0.00f, nullptr, SDL_FLIP_NONE);
			}
		}
	}
}
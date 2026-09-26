#include "game.h"
#include "tile_component.h"
#include "texture_manager.h"

namespace Radix
{
	TileComponent::TileComponent()
	{}

	TileComponent::~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	TileComponent::TileComponent(int source_rect_x, int source_rect_y, int x, int y, int tile_size, int tile_scale, unsigned int texture_id)
	{
		texture = Game::asset_manager.get_texture(texture_id);

		source_rect.x = source_rect_x;
		source_rect.y = source_rect_y;
		source_rect.w = tile_size;
		source_rect.h = tile_size;

		destination_rect.x = x;
		destination_rect.y = y;
		destination_rect.w = tile_size * tile_scale;
		destination_rect.h = tile_size * tile_scale;

		position.x = x;
		position.y = y;
	}

	void TileComponent::update(double delta_time)
	{
		destination_rect.x = position.x - Game::camera.x;
		destination_rect.y = position.y - Game::camera.y;
	}

	void TileComponent::render()
	{
		TextureManager::draw(texture, source_rect, destination_rect, SDL_FLIP_NONE);
	}
}
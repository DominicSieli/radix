#include "game.h"
#include "tile_component.h"
#include "texture_manager.h"

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
		destination_rect.x = position.x - static_cast<float>(Game::camera.x);
		destination_rect.y = position.y - static_cast<float>(Game::camera.y);
	}

	void TileComponent::render()
	{
		TextureManager::draw(texture, source_rect, destination_rect, SDL_FLIP_NONE);
	}
}
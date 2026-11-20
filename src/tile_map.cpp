#include <fstream>
#include <cstdlib>

#include "game.h"
#include "tile_map.h"
#include "tile_component.h"

namespace Radix
{
	TileMap::TileMap(const unsigned int& texture_id, const Vector2<unsigned int>& tiles, const float& tile_size, const float& scale):
		scale{scale}, tile_size{tile_size}, texture_id{texture_id}, tiles{tiles}
	{
		get_map_dimensions();
	}

	void TileMap::load_map(const std::string& file_path, const unsigned int& type_id, const unsigned int& render_layer)
	{
		std::fstream map_file;
		map_file.open(file_path);

		for(unsigned int y = 0; y < tiles.y; ++y)
		{
			for(unsigned int x = 0; x < tiles.x; ++x)
			{
				char character = 0;

				map_file.get(character);
				float source_y = static_cast<float>(std::strtol(&character, nullptr, 10) * tile_size);

				map_file.get(character);
				float source_x = static_cast<float>(std::strtol(&character, nullptr, 10) * tile_size);

				SDL_FRect source = {source_x, source_y, tile_size, tile_size};
				Vector2<float> position = {static_cast<float>(x) * (tile_size * scale), static_cast<float>(y) * (tile_size * scale)};

				add_tile(source, position, type_id, render_layer);
				map_file.ignore();
			}
		}

		map_file.close();
	}

	void TileMap::add_tile(const SDL_FRect& source, const Vector2<float>& position, const unsigned int& type_id, const unsigned int& render_layer)
	{
		Entity* new_tile = Game::entity_manager.create_entity(type_id, render_layer);
		new_tile->add_component<TileComponent>(texture_id, source, position, scale);
	}

	Vector2<float> TileMap::get_map_dimensions()
	{
		float tiles_x = static_cast<float>(tiles.x);
		float tiles_y = static_cast<float>(tiles.y);

		map_dimensions = Vector2<float>((tiles_x * tile_size * scale), (tiles_y * tile_size * scale));

		return map_dimensions;
	}
}
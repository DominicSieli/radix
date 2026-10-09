#include <fstream>

#include "game.h"
#include "tile_map.h"
#include "tile_component.h"

namespace Radix
{
	TileMap::TileMap()
	{}

	TileMap::TileMap(const unsigned int& texture_id, const unsigned int& scale, const unsigned int& tile_size):
		scale{scale}, tile_size{tile_size}, texture_id{texture_id}
	{}

	void TileMap::load_map(const std::string& file_path, const Vector2<int>& map_size, const std::string& name, const unsigned int& render_layer)
	{
		std::fstream map_file;
		map_file.open(file_path);

		for(int y = 0; y < map_size.y; y++)
		{
			for(int x = 0; x < map_size.x; x++)
			{
				char character = 0;
				map_file.get(character);
				float source_rect_y = static_cast<float>(atoi(&character) * tile_size);
				map_file.get(character);
				float source_rect_x = static_cast<float>(atoi(&character) * tile_size);
				add_tile(Vector2<float>(source_rect_x, source_rect_y), Vector2<float>(x * (scale * tile_size), y * (scale * tile_size)), name, render_layer);
				map_file.ignore();
			}
		}

		map_file.close();
	}

	void TileMap::add_tile(const Vector2<float>& rect_source, const Vector2<float>& rect_position, const std::string& name, const unsigned int& render_layer)
	{
		Entity* new_tile = Game::entity_manager.add_entity(name, render_layer);
		new_tile->add_component<TileComponent>(rect_source, rect_position, tile_size, scale, texture_id);
	}
}
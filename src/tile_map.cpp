#include <fstream>

#include "game.h"
#include "tile_map.h"
#include "tile_component.h"

namespace Radix
{
	TileMap::TileMap()
	{}

	TileMap::~TileMap()
	{}

	TileMap::TileMap(unsigned int texture_id, int scale, int tile_size)
	{
		this->scale = scale;
		this->tile_size = tile_size;
		this->texture_id = texture_id;
	}

	void TileMap::load_map(std::string file_path, int map_size_x, int map_size_y, std::string name, unsigned int render_layer)
	{
		std::fstream map_file;
		map_file.open(file_path);

		for(int y = 0; y < map_size_y; y++)
		{
			for(int x = 0; x < map_size_x; x++)
			{
				char character;
				map_file.get(character);
				int source_rect_y = atoi(&character) * tile_size;
				map_file.get(character);
				int source_rect_x = atoi(&character) * tile_size;
				add_tile(source_rect_x, source_rect_y, x * (scale * tile_size), y * (scale * tile_size), name, render_layer);
				map_file.ignore();
			}
		}

		map_file.close();
	}

	void TileMap::add_tile(int source_rect_x, int source_rect_y, int x, int y, std::string name, unsigned int render_layer)
	{
		Entity* new_tile(Game::entity_manager.add_entity(name, render_layer));
		new_tile->add_component<TileComponent>(source_rect_x, source_rect_y, x, y, tile_size, scale, texture_id);
	}
}
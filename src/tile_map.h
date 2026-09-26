#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

namespace Radix
{
	class TileMap
	{
		private:
			unsigned int scale;
			unsigned int tile_size;
			unsigned int texture_id;

		public:
			TileMap();

			~TileMap();

			TileMap(unsigned int, unsigned int, unsigned int);

			void load_map(std::string, int, int, std::string name, unsigned int render_layer);

			void add_tile(int, int, int, int, std::string name, unsigned int render_layer);
	};
}

#endif
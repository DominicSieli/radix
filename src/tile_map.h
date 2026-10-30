#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

#include "vectors.h"

namespace Radix
{
	class TileMap
	{
		private:
			unsigned int scale;
			Vector2<int> map_size;
			unsigned int tile_size;
			unsigned int texture_id;
			Vector2<int> map_dimensions;

		public:
			TileMap();

			TileMap(const unsigned int&, const Vector2<int>&, const unsigned int&, const unsigned int&);

			void load_map(const std::string&, const unsigned int&, const unsigned int&);

			void add_tile(const Vector2<float>&, const Vector2<float>&, const unsigned int&, const unsigned int&);

			Vector2<int> get_map_dimensions();
	};
}

#endif
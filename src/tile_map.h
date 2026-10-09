#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

#include "vector_2.h"

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

			TileMap(const unsigned int&, const unsigned int&, const unsigned int&);

			void load_map(const std::string&, const Vector2<int>&, const std::string& name, const unsigned int& render_layer);

			void add_tile(const Vector2<float>&, const Vector2<float>&, const std::string& name, const unsigned int& render_layer);
	};
}

#endif
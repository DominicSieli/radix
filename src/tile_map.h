#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>
#include <SDL3/SDL.h>

#include "vectors.h"

namespace Radix
{
	class TileMap
	{
		private:
			float scale;
			float tile_size;
			unsigned int texture_id;
			Vector2<unsigned int> tiles;
			Vector2<float> map_dimensions;

		public:
			TileMap(const unsigned int&, const Vector2<unsigned int>&, const float&, const float&);

			void load_map(const std::string&, const unsigned int&, const unsigned int&);

			void add_tile(const SDL_FRect&, const Vector2<float>&, const unsigned int&, const unsigned int&);

			Vector2<float> get_map_dimensions();
	};
}

#endif
#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <string>

#include "entity_manager.h"

namespace Radix
{
	class TileMap
	{
		private:
			int scale;
			int tile_size;
			unsigned int texture_id;
			EntityManager* entity_manager;

		public:
			TileMap(const unsigned int&, EntityManager*, int, int);

			~TileMap();

			void load_map(std::string, int, int);

			void add_tile(int, int, int, int);
	};
}

#endif
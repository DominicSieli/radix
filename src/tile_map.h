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
			std::string texture_id;
			EntityManager* entity_manager;

		public:
			TileMap(std::string, EntityManager*, int, int);

			~TileMap();

			void load_map(std::string, int, int);

			void add_tile(int, int, int, int);
	};
}

#endif
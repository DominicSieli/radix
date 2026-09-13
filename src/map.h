#ifndef MAP_H
#define MAP_H

#include <string>

#include "entity_manager.h"

namespace radix
{
	class Map
	{
		private:
			int scale;
			int tile_size;
			std::string texture_id;
			EntityManager* entity_manager;

		public:
			Map(std::string, EntityManager*, int, int);

			~Map();

			void load_map(std::string, int, int);

			void add_tile(int, int, int, int);
	};
}

#endif
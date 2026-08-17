#ifndef MAP_H
#define MAP_H

#include <string>

namespace radix
{
	class Map
	{
		private:
			int scale;
			int tile_size;
			std::string texture_id;

		public:
			Map(std::string, int, int);

			~Map();

			void load_map(std::string, int, int);

			void add_tile(int, int, int, int);
	};
}

#endif
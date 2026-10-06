#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>

#include "entity.h"

namespace Radix
{
	class EntityManager
	{
		public:
			std::vector<Entity*> entities;

			EntityManager();

			~EntityManager();

			void clear_entities();

			void update(float);

			bool is_empty();

			Entity* add_entity(const std::string&, const unsigned int&);

			Entity* get_entity_by_id(unsigned int);

			std::vector<Entity*> get_entities();

			std::vector<Entity*> get_entities_by_render_layer(unsigned int);

			void destroy_inactive_entities();

			unsigned int entity_count();
	};
}

#endif
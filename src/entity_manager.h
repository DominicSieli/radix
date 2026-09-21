#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>

#include "entity.h"
#include "component.h"

namespace Radix
{
	class EntityManager
	{
		public:
			std::vector<Entity*> entities;

			EntityManager();

			void clear();

			void update(float);

			void render();

			bool is_empty() const;

			Entity* add_entity(std::string, const unsigned int&);

			std::vector<Entity*> get_entities() const;

			std::vector<Entity*> get_entities_by_layer(const unsigned int&) const;

			void destroy_inactive_entities();

			unsigned int entity_count();
	};
}

#endif
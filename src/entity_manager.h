#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>

#include "entity.h"
#include "component.h"
#include "collision_tags.h"

namespace Radix
{
	class EntityManager
	{
		private:
			std::vector<Entity*> entities;

		public:
			EntityManager();

			void clear();

			void update(float);

			void render();

			bool is_empty() const;

			Entity* add_entity(std::string, const unsigned int&);

			std::vector<Entity*> get_entities() const;

			std::vector<Entity*> get_entities_by_layer(const unsigned int&) const;

			Collisions check_collisions() const;

			void destroy_inactive_entities();

			unsigned int entity_count();
	};
}

#endif
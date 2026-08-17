#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <vector>

#include "entity.h"
#include "component.h"

namespace radix
{
	class EntityManager
	{
		private:
			std::vector<Entity*> entities;

		public:
			void clear();

			void update(float);

			void render();

			bool is_empty() const;

			void list_entities() const;

			Entity& add_entity(std::string, LayerType);

			std::vector<Entity*> get_entities() const;

			std::vector<Entity*> get_entities_by_layer(LayerType) const;

			CollisionType check_collisions() const;

			void destroy_inactive_entities();

			unsigned int entity_count();
	};
}

#endif
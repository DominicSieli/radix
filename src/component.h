#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

namespace Radix
{
	class Entity;

	class Component
	{
		private:
			Entity* entity;
			bool active = true;

		public:
			virtual ~Component()
			{}

			virtual void initialize()
			{}

			virtual void update(const float&)
			{}

			virtual void render()
			{}

			Entity* get_entity()
			{
				return entity;
			}

			void set_entity(Entity* new_entity)
			{
				entity = new_entity;
			}

			bool is_active()
			{
				return active;
			}

			void set_active()
			{
				active = true;
			}

			void set_inactive()
			{
				active = false;
			}
	};
}

#endif
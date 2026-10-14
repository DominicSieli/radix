#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

namespace Radix
{
	class Entity;

	class Component
	{
		private:
			bool active = true;

		public:
			Entity* entity;

			virtual ~Component()
			{}

			virtual void initialize()
			{}

			virtual void update(const float&)
			{}

			virtual void render()
			{}

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
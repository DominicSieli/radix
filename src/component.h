#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

namespace Radix
{
	class Entity;

	class Component
	{
		public:
			Entity* entity;

			virtual ~Component()
			{}

			virtual void initialize()
			{}

			virtual void update(double)
			{}

			virtual void render()
			{}
	};
}

#endif
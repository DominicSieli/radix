#ifndef COMPONENT_H
#define COMPONENT_H

#include "entity.h"

namespace radix
{
	class Entity;

	class Component
	{
		public:
			Entity* entity;

			virtual ~Component() {}

			virtual void initialize() {}

			virtual void update(float) {}

			virtual void render() {}
	};
}

#endif
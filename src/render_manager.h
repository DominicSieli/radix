#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

#include "entity_manager.h"

namespace Radix
{
	class RenderManager
	{
		public:
			EntityManager* entity_manager;

			RenderManager();

			RenderManager(EntityManager*);

			void render();
	};
}

#endif
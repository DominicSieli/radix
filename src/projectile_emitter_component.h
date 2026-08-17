#ifndef PROJECTILE_EMITTER_COMPONENT_H
#define PROJECTILE_EMITTER_COMPONENT_H

#include "entity_manager.h"
#include "transform_component.h"
#include "../include/glm/glm.hpp"

namespace radix
{
	class ProjectileEmitterComponent: public Component
	{
		private:
			bool loop;
			int speed;
			int range;
			float radian;
			glm::vec2 origin;
			TransformComponent* transform_component;

		public:
			ProjectileEmitterComponent(int, int, int, bool);

			void initialize() override;

			void update(float) override;
	};
}

#endif
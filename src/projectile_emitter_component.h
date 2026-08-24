#ifndef PROJECTILE_EMITTER_COMPONENT_H
#define PROJECTILE_EMITTER_COMPONENT_H

#include "vector2.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace radix
{
	class ProjectileEmitterComponent: public Component
	{
		private:
			bool loop;
			int speed;
			int range;
			float radian;
			Vector2 origin;
			TransformComponent* transform_component;

		public:
			ProjectileEmitterComponent(int, int, int, bool);

			void initialize() override;

			void update(float) override;
	};
}

#endif
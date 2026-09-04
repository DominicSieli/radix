#ifndef SPAWNER_COMPONENT_H
#define SPAWNER_COMPONENT_H

#include "vector2.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace radix
{
	class SpawnerComponent: public Component
	{
		private:
			bool loop;
			int speed;
			int range;
			float radian;
			Vector2 origin;
			TransformComponent* transform_component;

		public:
			SpawnerComponent(int, int, int, bool);

			void initialize() override;

			void update(float) override;
	};
}

#endif
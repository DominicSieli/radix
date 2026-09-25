#ifndef SPAWNER_COMPONENT_H
#define SPAWNER_COMPONENT_H

#include "vector_2.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class SpawnerComponent: public Component
	{
		private:
			bool loop;
			float radian;
			Vector2 origin;
			unsigned int speed;
			unsigned int range;
			unsigned int degree;
			TransformComponent* transform_component;

		public:
			SpawnerComponent();

			~SpawnerComponent();

			SpawnerComponent(unsigned int, unsigned int, unsigned int, bool);

			void initialize() override;

			void update(float) override;
	};
}

#endif
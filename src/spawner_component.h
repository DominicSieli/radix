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
			float range;
			TransformComponent* transform_component;

		public:
			SpawnerComponent();

			~SpawnerComponent();

			SpawnerComponent(float, bool);

			void initialize() override;

			void update(float) override;
	};
}

#endif
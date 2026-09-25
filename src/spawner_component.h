#ifndef SPAWNER_COMPONENT_H
#define SPAWNER_COMPONENT_H

#include "point_2d.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class SpawnerComponent: public Component
	{
		private:
			bool loop;
			float radian;
			Point2D origin;
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
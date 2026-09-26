#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "vector_2.h"
#include "entity_manager.h"

namespace Radix
{
	class TransformComponent: public Component
	{
		public:
			double rotation;
			Vector2<double> scale;
			Vector2<unsigned int> position;
			Vector2<unsigned int> dimensions;

			TransformComponent();

			~TransformComponent();

			TransformComponent(Vector2<unsigned int>, Vector2<unsigned int>, Vector2<double>, double);

			void initialize() override;

			void update(double) override;

			void render() override;

			void rotate(double);

			void rescale(Vector2<double>);

			void translate(Vector2<unsigned int>);
	};
}

#endif
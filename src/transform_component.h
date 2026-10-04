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
			float rotation;
			Vector2<float> scale;
			Vector2<float> position;

			TransformComponent();

			~TransformComponent();

			TransformComponent(Vector2<float>, Vector2<float>, float);

			void initialize() override;

			void update(float) override;

			void render() override;

			void rotate(float);

			void rescale(Vector2<float>);

			void translate(Vector2<float>);
	};
}

#endif
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
			float scale;
			Vector2 position;
			Vector2 velocity;
			Vector2 dimension;

			TransformComponent();

			~TransformComponent();

			TransformComponent(int, int, int, int, int, int, float);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
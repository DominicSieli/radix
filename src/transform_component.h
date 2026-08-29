#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "vector2.h"
#include "entity_manager.h"

namespace radix
{
	class TransformComponent: public Component
	{
		public:
			int scale;
			Vector2 position;
			Vector2 velocity;
			Vector2 dimension;

			TransformComponent(int, int, int, int, int, int, int);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "point_2d.h"
#include "entity_manager.h"

namespace Radix
{
	class TransformComponent: public Component
	{
		public:
			int scale;
			Point2D position;
			Point2D velocity;
			Point2D dimension;

			TransformComponent();

			~TransformComponent();

			TransformComponent(int, int, int, int, int, int, int);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
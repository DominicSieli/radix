#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL2/SDL.h>

#include "game.h"
#include "entity_manager.h"
#include "../include/glm/glm.hpp"

namespace radix
{
	class TransformComponent: public Component
	{
		public:
			int scale;
			glm::vec2 position;
			glm::vec2 velocity;
			glm::vec2 dimension;

			TransformComponent(int, int, int, int, int, int, int);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
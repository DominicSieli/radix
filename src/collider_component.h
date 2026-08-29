#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace radix
{
	class ColliderComponent: public Component
	{
		public:
			std::string tag;
			SDL_Rect collider;
			SDL_Rect source_rectangle;
			SDL_Rect destination_rectangle;
			TransformComponent* transform_component;

			ColliderComponent(std::string, int, int, int, int);

			void initialize() override;

			void update(float) override;
	};
}

#endif
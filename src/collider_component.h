#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "vector_2.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class ColliderComponent: public Component
	{
		public:
			unsigned int tag;
			SDL_Rect collider;
			SDL_Rect source_rect;
			SDL_Rect destination_rect;
			Vector2<int> dimensions;
			TransformComponent* transform_component;

			ColliderComponent();

			ColliderComponent(unsigned int, Vector2<int>);

			~ColliderComponent() override;

			void initialize() override;

			void update(float) override;
	};
}

#endif
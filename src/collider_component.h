#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "vectors.h"
#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class ColliderComponent: public Component
	{
		private:
			unsigned int tag;
			SDL_Rect collider;
			SDL_Rect source_rect;
			SDL_Rect destination_rect;
			Vector2<int> dimensions;
			TransformComponent* transform_component;

		public:
			ColliderComponent(const unsigned int&, const Vector2<int>&);

			void initialize() override;

			void update(const float&) override;

			unsigned int get_tag();

			SDL_Rect get_collider();
	};
}

#endif
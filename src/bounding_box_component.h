#ifndef BOUNDING_BOX_COMPONENT_H
#define BOUNDING_BOX_COMPONENT_H

#include <vector>
#include <SDL3/SDL.h>

#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class BoundingBoxComponent: public Component
	{
		private:
			unsigned int tag;
			SDL_Renderer* renderer;
			std::vector<SDL_FPoint> vertices;
			TransformComponent* transform_component;

		public:
			BoundingBoxComponent(const unsigned int&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			unsigned int get_tag();

			std::vector<SDL_FPoint> get_vertices();
	};
}

#endif

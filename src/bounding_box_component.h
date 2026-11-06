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
			SDL_Color color;
			unsigned int tag;
			SDL_Renderer* renderer;
			std::vector<SDL_FPoint> geometry;
			TransformComponent* transform_component;

		public:
			BoundingBoxComponent(const unsigned int&, const SDL_Color&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			unsigned int get_tag();

			void set_color(const SDL_Color&);

			std::vector<SDL_FPoint> get_geometry();
	};
}

#endif

#ifndef POLYGON_RECT_COMPONENT_H
#define POLYGON_RECT_COMPONENT_H

#include <vector>
#include <SDL3/SDL.h>

#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class PolygonRectComponent: public Component
	{
		private:
			unsigned int tag;
			SDL_Color color;
			bool render_lines;
			SDL_Renderer* renderer;
			std::vector<SDL_FPoint> vertices;
			TransformComponent* transform_component;

		public:
			PolygonRectComponent(const unsigned int&, const SDL_Color&, const bool&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			unsigned int get_tag();

			void set_color(const SDL_Color&);

			const std::vector<SDL_FPoint>& get_geometry();
	};
}

#endif

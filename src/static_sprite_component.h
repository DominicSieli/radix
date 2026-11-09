#ifndef STATIC_SPRITE_COMPONENT_H
#define STATIC_SPRITE_COMPONENT_H

#include <span>
#include <SDL3/SDL.h>

#include "transform_component.h"
#include "polygon_rect_component.h"

namespace Radix
{
	class StaticSpriteComponent: public Component
	{
		private:
			bool fixed;
			unsigned int texture_id;

			SDL_FRect source;
			SDL_Texture* texture;
			SDL_FRect destination;
			SDL_Renderer* renderer;
			TransformComponent* transform_component;
			PolygonRectComponent* polygon_rect_component;

		public:
			StaticSpriteComponent(const bool&, const unsigned int&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void set_texture(const unsigned int&);

		private:
			void render_geometry(SDL_Renderer*, SDL_Texture*, const std::vector<SDL_FPoint>&);
	};
}

#endif
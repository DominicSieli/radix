#ifndef STATIC_SPRITE_COMPONENT_H
#define STATIC_SPRITE_COMPONENT_H

#include <SDL3/SDL.h>

#include "vector_2.h"
#include "asset_manager.h"
#include "texture_manager.h"
#include "transform_component.h"

namespace Radix
{
	class StaticSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FRect source;
			SDL_Texture* texture;
			SDL_FRect destination;
			Vector2<int> dimensions;
			TransformComponent* transform_component;
			SDL_FlipMode sprite_flip = SDL_FLIP_NONE;

		public:
			StaticSpriteComponent();

			StaticSpriteComponent(unsigned int, Vector2<int>, bool);

			~StaticSpriteComponent();

			void initialize() override;

			void set_texture(unsigned int);

			void update(float) override;

			void render() override;
	};
}

#endif
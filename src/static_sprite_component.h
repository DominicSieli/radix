#ifndef STATIC_SPRITE_COMPONENT_H
#define STATIC_SPRITE_COMPONENT_H

#include <string>
#include <SDL3/SDL.h>

#include "asset_manager.h"
#include "texture_manager.h"
#include "transform_component.h"

namespace radix
{
	class StaticSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FRect source;
			SDL_Texture* texture;
			SDL_FRect destination;
			unsigned int index = 0;
			TransformComponent* transform_component;

		public:
			SDL_FlipMode sprite_flip = SDL_FLIP_NONE;

			StaticSpriteComponent();

			StaticSpriteComponent(const char*);

			void set_texture(std::string);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
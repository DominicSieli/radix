#ifndef ANIMATED_SPRITE_COMPONENT_H
#define ANIMATED_SPRITE_COMPONENT_H

#include <SDL3/SDL.h>

#include "animation.h"
#include "asset_manager.h"
#include "texture_manager.h"
#include "transform_component.h"

namespace Radix
{
	class AnimatedSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FRect source;
			unsigned int index;
			SDL_Texture* texture;
			SDL_FRect destination;
			unsigned int current_animation;
			unsigned int default_animation;
			TransformComponent* transform_component;
			SDL_FlipMode sprite_flip = SDL_FLIP_NONE;
			std::map<unsigned int, Animation> animations;

		public:
			AnimatedSpriteComponent();

			AnimatedSpriteComponent(const unsigned int&, const std::map<unsigned int, Animation>&, const unsigned int&, const bool&);

			void initialize() override;

			void play(unsigned int);

			void set_texture(const unsigned int&);

			void update(float) override;

			void render() override;
	};
}

#endif
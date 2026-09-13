#ifndef ANIMATED_SPRITE_COMPONENT_H
#define ANIMATED_SPRITE_COMPONENT_H

#include <string>
#include <SDL3/SDL.h>

#include "animation.h"
#include "asset_manager.h"
#include "texture_manager.h"
#include "transform_component.h"

namespace radix
{
	class AnimatedSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FRect source;
			SDL_Texture* texture;
			SDL_FRect destination;
			unsigned int index = 0;
			std::string current_animation;
			std::string default_animation;
			TransformComponent* transform_component;
			std::map<std::string, Animation>* animations;

		public:
			SDL_FlipMode sprite_flip = SDL_FLIP_NONE;

			AnimatedSpriteComponent();

			AnimatedSpriteComponent(std::string, std::map<std::string, Animation>*, std::string, bool, bool);

			void play(std::string);

			void set_texture(std::string);

			void initialize() override;

			void update(float) override;

			void render() override;
	};
}

#endif
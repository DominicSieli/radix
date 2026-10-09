#ifndef ANIMATED_SPRITE_COMPONENT_H
#define ANIMATED_SPRITE_COMPONENT_H

#include <SDL3/SDL.h>

#include "vector_2.h"
#include "animation.h"
#include "transform_component.h"

namespace Radix
{
	class AnimatedSpriteComponent: public Component
	{
		private:
			std::map<unsigned int, Animation> animations;
			unsigned int texture_id;
			unsigned int default_animation;
			unsigned int current_animation;
			Vector2<int> dimensions;
			bool fixed;

			SDL_FRect source;
			unsigned int index;
			SDL_Texture* texture;
			SDL_FRect destination;
			TransformComponent* transform_component;
			SDL_FlipMode sprite_flip = SDL_FLIP_NONE;

		public:
			AnimatedSpriteComponent(const std::map<unsigned int, Animation>&, const unsigned int&, const unsigned int&, const Vector2<int>&, const bool&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void play(const unsigned int&);

			void set_texture(const unsigned int&);
	};
}

#endif
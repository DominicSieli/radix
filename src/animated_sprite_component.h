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
			AnimatedSpriteComponent();

			AnimatedSpriteComponent(const std::map<unsigned int, Animation>&, unsigned int, unsigned int, Vector2<int>, bool);

			~AnimatedSpriteComponent() override;

			void initialize() override;

			void update(float) override;

			void render() override;

			void play(unsigned int);

			void set_texture(unsigned int);
	};
}

#endif
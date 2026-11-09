#ifndef ANIMATED_SPRITE_COMPONENT_H
#define ANIMATED_SPRITE_COMPONENT_H

#include <SDL3/SDL.h>

#include "animation.h"
#include "transform_component.h"
#include "polygon_rect_component.h"

namespace Radix
{
	class AnimatedSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FlipMode flip;
			unsigned int texture_id;
			unsigned int default_animation;
			std::unordered_map<unsigned int, Animation> animations;

			bool paused;
			SDL_FRect source;
			unsigned int index;
			SDL_Texture* texture;
			SDL_FRect destination;
			SDL_Renderer* renderer;
			float animation_progress;
			unsigned int current_frame;
			unsigned int current_animation;
			TransformComponent* transform_component;
			PolygonRectComponent* polygon_rect_component;

		public:
			AnimatedSpriteComponent(const bool&, const SDL_FlipMode&, const unsigned int&, const unsigned int&, const std::unordered_map<unsigned int, Animation>&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void pause();

			void unpause();

			bool is_paused();

			void play(const unsigned int&);

			void set_texture(const unsigned int&);

		private:
			void render_geometry(SDL_Renderer*, SDL_Texture*, const std::vector<SDL_FPoint>&);
	};
}

#endif
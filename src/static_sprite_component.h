#ifndef STATIC_SPRITE_COMPONENT_H
#define STATIC_SPRITE_COMPONENT_H

#include <SDL3/SDL.h>

#include "vectors.h"
#include "asset_manager.h"
#include "transform_component.h"

namespace Radix
{
	class StaticSpriteComponent: public Component
	{
		private:
			bool fixed;
			SDL_FlipMode flip;
			unsigned int texture_id;
			Vector2<float> dimensions;

			SDL_FRect source;
			SDL_Texture* texture;
			SDL_FRect destination;
			TransformComponent* transform_component;

		public:
			StaticSpriteComponent(const bool&, const SDL_FlipMode&, const unsigned int&, const Vector2<float>&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void set_texture(const unsigned int&);
	};
}

#endif
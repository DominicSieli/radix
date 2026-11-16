#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL3/SDL.h>

#include "vectors.h"
#include "entity_manager.h"
#include "texture_manager.h"

namespace Radix
{
	class TileComponent: public Component
	{
		private:
			float scale;
			SDL_Texture* texture;
			SDL_FRect source;
			SDL_FRect destination;
			Vector2<float> position;

		public:
			TileComponent(const unsigned int&, const SDL_FRect&, const Vector2<float>&, const float&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void set_texture(const unsigned int&);
	};
}

#endif
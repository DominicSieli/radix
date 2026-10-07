#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL3/SDL.h>

#include "vector_2.h"
#include "asset_manager.h"
#include "entity_manager.h"

namespace Radix
{
	class TileComponent: public Component
	{
		public:
			SDL_Texture* texture;
			SDL_FRect source_rect;
			SDL_FRect destination_rect;
			Vector2<float> position;

			TileComponent();

			TileComponent(float, float, float, float, int, float, unsigned int);

			~TileComponent() override;

			void update(float) override;

			void render() override;
	};
}

#endif
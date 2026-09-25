#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL3/SDL.h>

#include "point_2d.h"
#include "asset_manager.h"
#include "entity_manager.h"

namespace Radix
{
	class TileComponent: public Component
	{
		public:
			Point2D position;
			SDL_Texture* texture;
			SDL_FRect source_rect;
			SDL_FRect destination_rect;

			TileComponent();

			~TileComponent();

			TileComponent(int, int, int, int, int, int, unsigned int);

			void update(float) override;

			void render() override;
	};
}

#endif
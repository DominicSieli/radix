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
		private:
			SDL_Texture* texture;
			SDL_FRect source_rect;
			SDL_FRect destination_rect;
			Vector2<float> position;

		public:
			TileComponent(const Vector2<float>&, const Vector2<float>&, const int&, const float&, const unsigned int&);

			~TileComponent() override;

			void update(const float&) override;

			void render() override;
	};
}

#endif
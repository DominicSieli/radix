#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL2/SDL.h>

#include "asset_manager.h"
#include "entity_manager.h"
#include "../include/glm/glm.hpp"

namespace radix
{
	class TileComponent: public Component
	{
		public:
			glm::vec2 position;
			SDL_Texture* texture;
			SDL_Rect source_rectangle;
			SDL_Rect destination_rectangle;

			TileComponent(int, int, int, int, int, int, std::string);

			~TileComponent();

			void update(float) override;

			void render() override;
	};
}

#endif
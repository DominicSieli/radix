#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "font_manager.h"
#include "asset_manager.h"
#include "entity_manager.h"

namespace Radix
{
	class TextComponent: public Component
	{
		private:
			SDL_Color color;
			std::string text;
			SDL_FRect position;
			SDL_Texture* texture;
			unsigned int font_family;

		public:
			TextComponent();

			~TextComponent();

			TextComponent(int, int, std::string, unsigned int, SDL_Color);

			void set_text(std::string, unsigned int);

			void render() override;
	};
}

#endif
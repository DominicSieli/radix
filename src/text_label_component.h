#ifndef TEXT_LABEL_COMPONENT_H
#define TEXT_LABEL_COMPONENT_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "font_manager.h"
#include "asset_manager.h"
#include "entity_manager.h"

namespace radix
{
	class TextLabelComponent: public Component
	{
		private:
			SDL_Color color;
			std::string text;
			SDL_FRect position;
			SDL_Texture* texture;
			std::string font_family;

		public:
			TextLabelComponent(int, int, std::string, std::string, const SDL_Color&);

			void set_label_text(std::string, std::string);

			void render() override;
	};
}

#endif
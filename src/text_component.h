#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "vector_2.h"
#include "font_manager.h"
#include "asset_manager.h"
#include "entity_manager.h"

namespace Radix
{
	class TextComponent: public Component
	{
		private:
			std::string text;
			unsigned int font_family;
			SDL_Color color;

			SDL_FRect position;
			SDL_Texture* texture;

		public:
			TextComponent();

			TextComponent(const Vector2<float>&, const std::string&, const unsigned int&, const SDL_Color&);

			~TextComponent() override;

			void set_text(const std::string&, const unsigned int&);

			void render() override;
	};
}

#endif
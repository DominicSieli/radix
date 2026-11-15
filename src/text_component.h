#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "vectors.h"
#include "font_manager.h"
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
			SDL_Renderer* renderer;

		public:
			TextComponent(const Vector2<float>&, const std::string&, const unsigned int&, const SDL_Color&);

			void initialize() override;

			void set_text(const std::string&, const unsigned int&);

			void render() override;
	};
}

#endif
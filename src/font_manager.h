#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL3/SDL.h>
#include <unordered_map>
#include <SDL3_ttf/SDL_ttf.h>

#include "entity_manager.h"

namespace Radix
{
	class FontManager
	{
		private:
			std::unordered_map<unsigned int, TTF_Font*> fonts;

		public:
			FontManager();

			~FontManager();

			void destroy();

			void clear_fonts();

			void delete_font(const unsigned int&);

			TTF_Font* get_font(const unsigned int&);

			void add_font(const unsigned int&, const char*, const float&);
	};
}

#endif
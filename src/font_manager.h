#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace Radix
{
	class FontManager
	{
		public:
			FontManager();

			static void draw_font(SDL_Texture*, const SDL_FRect&);

			static TTF_Font* load_font(const char*, const float&);
	};
}

#endif
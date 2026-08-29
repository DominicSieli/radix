#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

namespace radix
{
	class FontManager
	{
		public:
			static TTF_Font* load_font(const char*, int);

			static void draw_font(SDL_Texture*, SDL_FRect);
	};
}

#endif
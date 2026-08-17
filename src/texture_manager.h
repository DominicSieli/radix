#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

namespace radix
{
	class TextureManager
	{
		public:
			static SDL_Texture* load_texture(const char*);

			static void draw(SDL_Texture*, SDL_Rect, SDL_Rect, SDL_RendererFlip);
	};
}

#endif
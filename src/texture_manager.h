#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Radix
{
	class TextureManager
	{
		public:
			static SDL_Texture* load_texture(const char*);

			static void draw(SDL_Texture*, SDL_FRect, SDL_FRect, SDL_FlipMode);
	};
}

#endif
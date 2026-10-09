#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Radix
{
	class TextureManager
	{
		public:
			TextureManager();

			static SDL_Texture* load_texture(const char*);

			static void draw(SDL_Texture*, const SDL_FRect&, const SDL_FRect&, const SDL_FlipMode&);
	};
}

#endif
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

			static void delete_texture(SDL_Texture*);

			static SDL_Texture* load_texture(const char*);

			static void draw(SDL_Texture*, const SDL_FRect&, const SDL_FRect&, const float&, const SDL_FlipMode&);
	};
}

#endif
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL3/SDL.h>
#include <unordered_map>
#include <SDL3_image/SDL_image.h>

#include "entity_manager.h"

namespace Radix
{
	class TextureManager
	{
		private:
			std::unordered_map<unsigned int, SDL_Texture*> textures;

		public:
			TextureManager();

			~TextureManager();

			void destroy();

			void clear_textures();

			void delete_texture(const unsigned int&);

			SDL_Texture* get_texture(const unsigned int&);

			void add_texture(const unsigned int&, const char*);
	};
}

#endif
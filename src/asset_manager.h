#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SDL3/SDL.h>
#include <unordered_map>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

#include "entity_manager.h"

namespace Radix
{
	class AssetManager
	{
		private:
			std::unordered_map<unsigned int, TTF_Font*> fonts;
			std::unordered_map<unsigned int, SDL_Texture*> textures;

		public:
			AssetManager();

			~AssetManager();

			void clear_all();

			void clear_fonts();

			void clear_textures();

			void delete_font(const unsigned int&);

			void delete_texture(const unsigned int&);

			TTF_Font* get_font(const unsigned int&);

			SDL_Texture* get_texture(const unsigned int&);

			void add_texture(const unsigned int&, const char*);

			void add_font(const unsigned int&, const char*, const float&);
	};
}

#endif
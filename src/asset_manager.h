#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>

#include "game.h"
#include "font_manager.h"
#include "entity_manager.h"
#include "texture_manager.h"

namespace Radix
{
	class AssetManager
	{
		private:
			std::map<unsigned int, TTF_Font*> fonts;
			std::map<unsigned int, SDL_Texture*> textures;

		public:
			AssetManager();

			~AssetManager();

			void clear();

			TTF_Font* get_font(unsigned int);

			SDL_Texture* get_texture(unsigned int);

			void add_texture(unsigned int, const char*);

			void add_font(unsigned int, const char*, int);
	};
}

#endif
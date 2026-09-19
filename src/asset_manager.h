#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "font_manager.h"
#include "entity_manager.h"
#include "texture_manager.h"

namespace Radix
{
	class AssetManager
	{
		private:
			EntityManager* entity_manager;
			std::map<unsigned int, TTF_Font*> fonts;
			std::map<unsigned int, SDL_Texture*> textures;

		public:
			AssetManager(EntityManager*);

			~AssetManager();

			void clear();

			TTF_Font* get_font(const unsigned int&);

			SDL_Texture* get_texture(const unsigned int&);

			void add_texture(const unsigned int&, const char*);

			void add_font(const unsigned int&, const char*, int);
	};
}

#endif
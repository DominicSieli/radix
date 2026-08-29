#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include <SDL3_ttf/SDL_ttf.h>

#include "game.h"
#include "font_manager.h"
#include "entity_manager.h"
#include "texture_manager.h"

namespace radix
{
	class AssetManager
	{
		private:
			EntityManager* entity_manager;
			std::map<std::string, TTF_Font*> fonts;
			std::map<std::string, SDL_Texture*> textures;

		public:
			AssetManager(EntityManager*);

			~AssetManager();

			void clear();

			TTF_Font* get_font(std::string);

			SDL_Texture* get_texture(std::string);

			void add_texture(std::string, const char*);

			void add_font(std::string, const char*, int);
	};
}

#endif
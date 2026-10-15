#include "game.h"
#include "asset_manager.h"

namespace Radix
{
	AssetManager::AssetManager()
	{}

	AssetManager::~AssetManager()
	{
		clear_all();
	}

	void AssetManager::clear_all()
	{
		clear_fonts();
		clear_textures();
	}

	void AssetManager::clear_fonts()
	{
		for(auto& [id, font] : fonts)
		{
			TTF_CloseFont(font);
		}

		fonts.clear();
	}

	void AssetManager::clear_textures()
	{
		for(auto& [id, texture] : textures)
		{
			SDL_DestroyTexture(texture);
		}

		textures.clear();
	}

	void AssetManager::delete_font(const unsigned int& id)
	{
		TTF_CloseFont(fonts[id]);
		fonts.erase(id);
	}

	void AssetManager::delete_texture(const unsigned int& id)
	{
		SDL_DestroyTexture(textures[id]);
		textures.erase(id);
	}

	TTF_Font* AssetManager::get_font(const unsigned int& id)
	{
		return fonts[id];
	}

	SDL_Texture* AssetManager::get_texture(const unsigned int& id)
	{
		return textures[id];
	}

	void AssetManager::add_texture(const unsigned int& id, const char* file_path)
	{
		SDL_Surface* surface = IMG_Load(file_path);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_DestroySurface(surface);
		textures.try_emplace(id, texture);
	}

	void AssetManager::add_font(const unsigned int& id, const char* file_path, const float& size)
	{
		fonts.try_emplace(id, TTF_OpenFont(file_path, size));
	}
}
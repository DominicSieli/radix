#include "game.h"
#include "texture_manager.h"

namespace Radix
{
	TextureManager::TextureManager()
	{}

	TextureManager::~TextureManager()
	{
		destroy();
	}

	void TextureManager::destroy()
	{
		clear_textures();
	}

	void TextureManager::clear_textures()
	{
		for(auto& [id, texture] : textures)
		{
			SDL_DestroyTexture(texture);
		}

		textures.clear();
	}

	void TextureManager::delete_texture(const unsigned int& id)
	{
		SDL_DestroyTexture(textures[id]);
		textures.erase(id);
	}

	SDL_Texture* TextureManager::get_texture(const unsigned int& id)
	{
		return textures[id];
	}

	void TextureManager::add_texture(const unsigned int& id, const char* file_path)
	{
		SDL_Surface* surface = IMG_Load(file_path);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::render_manager.get_renderer(), surface);
		SDL_DestroySurface(surface);
		textures.try_emplace(id, texture);
	}
}
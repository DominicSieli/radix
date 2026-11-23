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
			delete_texture(id);
		}

		textures.clear();
	}

	void TextureManager::delete_texture(const unsigned int& id)
	{
		if(textures.contains(id))
		{
			SDL_DestroyTexture(textures[id]);
			textures.erase(id);
		}
	}

	SDL_Texture* TextureManager::get_texture(const unsigned int& id)
	{
		return textures[id];
	}

	void TextureManager::add_texture(const unsigned int& id, const char* file_path)
	{
		SDL_Surface* surface = nullptr;
		SDL_Texture* texture = nullptr;
		SDL_Renderer* renderer = Game::render_manager.get_renderer();

		if(file_path)
		{
			surface = IMG_Load(file_path);
		}

		if(renderer && surface)
		{
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_DestroySurface(surface);
		}

		if(texture)
		{
			textures.try_emplace(id, texture);
		}
	}
}
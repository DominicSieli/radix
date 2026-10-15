#include "game.h"
#include "texture_manager.h"

namespace Radix
{
	TextureManager::TextureManager()
	{}

	void TextureManager::delete_texture(SDL_Texture* texture)
	{
		SDL_DestroyTexture(texture);
	}

	SDL_Texture* TextureManager::load_texture(const char* file_name)
	{
		SDL_Surface* surface = IMG_Load(file_name);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_DestroySurface(surface);

		return texture;
	}

	void TextureManager::draw(SDL_Texture* texture, const SDL_FRect& source, const SDL_FRect& destination, const float& rotation, const SDL_FlipMode& flip_mode)
	{
		SDL_RenderTextureRotated(Game::renderer, texture, &source, &destination, rotation, nullptr, flip_mode);
	}
}
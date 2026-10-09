#include "game.h"
#include "texture_manager.h"

namespace Radix
{
	TextureManager::TextureManager()
	{}

	SDL_Texture* TextureManager::load_texture(const char* file_name)
	{
		SDL_Surface* surface = IMG_Load(file_name);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_DestroySurface(surface);

		return texture;
	}

	void TextureManager::draw(SDL_Texture* texture, const SDL_FRect& source, const SDL_FRect& destination, const SDL_FlipMode& flip_mode)
	{
		SDL_RenderTextureRotated(Game::renderer, texture, &source, &destination, 0.00f, NULL, flip_mode);
	}
}
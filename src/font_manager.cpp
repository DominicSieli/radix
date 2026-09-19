#include "game.h"
#include "font_manager.h"

namespace Radix
{
	void FontManager::draw_font(SDL_Texture* texture, SDL_FRect position)
	{
		SDL_RenderTexture(Game::renderer, texture, NULL, &position);
	}

	TTF_Font* FontManager::load_font(const char* file_name, const unsigned int& font_size)
	{
		return TTF_OpenFont(file_name, font_size);
	}
}
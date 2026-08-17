#include "game.h"
#include "font_manager.h"

namespace radix
{
	TTF_Font* FontManager::load_font(const char* file_name, int font_size)
	{
		return TTF_OpenFont(file_name, font_size);
	}

	void FontManager::draw_font(SDL_Texture* texture, SDL_Rect position)
	{
		SDL_RenderCopy(Game::renderer, texture, nullptr, &position);
	}
}
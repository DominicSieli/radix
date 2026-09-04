#include "text_component.h"

namespace radix
{
	TextComponent::TextComponent(int x, int y, std::string text, std::string font_family, const SDL_Color& color)
	{
		this->position.x = x;
		this->position.y = y;
		this->text = text;
		this->font_family = font_family;
		this->color = color;
		set_text(text, font_family);
	}

	void TextComponent::set_text(std::string text, std::string font_family)
	{
		SDL_Surface* surface = TTF_RenderText_Blended(Game::asset_manager->get_font(font_family), text.c_str(), 0, color);
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_DestroySurface(surface);
		SDL_GetTextureSize(texture, &position.w, &position.h);
	}

	void TextComponent::render()
	{
		FontManager::draw_font(texture, position);
	}
}
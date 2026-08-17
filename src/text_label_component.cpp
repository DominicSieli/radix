#include "text_label_component.h"

namespace radix
{
	TextLabelComponent::TextLabelComponent(int x, int y, std::string text, std::string font_family, const SDL_Color& color)
	{
		this->position.x = x;
		this->position.y = y;
		this->text = text;
		this->font_family = font_family;
		this->color = color;
		set_label_text(text, font_family);
	}

	void TextLabelComponent::set_label_text(std::string text, std::string font_family)
	{
		SDL_Surface* surface = TTF_RenderText_Blended(Game::asset_manager->get_font(font_family), text.c_str(), color);
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_FreeSurface(surface);
		SDL_QueryTexture(texture, nullptr, nullptr, &position.w, &position.h);
	}

	void TextLabelComponent::render()
	{
		FontManager::draw_font(texture, position);
	}
}
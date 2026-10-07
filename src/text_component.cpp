#include "game.h"
#include "text_component.h"

namespace Radix
{
	TextComponent::TextComponent()
	{}

	TextComponent::TextComponent(float x, float y, std::string text, unsigned int font_family, SDL_Color color)
		: text{text}, font_family{font_family}, color{color}
	{
		this->position.x = x;
		this->position.y = y;
		set_text(text, font_family);
	}

	TextComponent::~TextComponent()
	{}

	void TextComponent::set_text(const std::string& text, const unsigned int& font_family)
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
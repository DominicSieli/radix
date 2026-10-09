#include "game.h"
#include "text_component.h"

namespace Radix
{
	TextComponent::TextComponent(const Vector2<float>& screen_position, const std::string& text, const unsigned int& font_family, const SDL_Color& color):
		text{text}, font_family{font_family}, color{color}
	{
		position.x = screen_position.x;
		position.y = screen_position.y;
		set_text(text, font_family);
	}

	void TextComponent::set_text(const std::string& text, const unsigned int& font_family)
	{
		SDL_Surface* surface = TTF_RenderText_Blended(Game::asset_manager.get_font(font_family), text.c_str(), 0, color);
		texture = SDL_CreateTextureFromSurface(Game::renderer, surface);
		SDL_DestroySurface(surface);
		SDL_GetTextureSize(texture, &position.w, &position.h);
	}

	void TextComponent::render()
	{
		FontManager::draw_font(texture, position);
	}
}
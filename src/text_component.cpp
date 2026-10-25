#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

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
		texture = SDL_CreateTextureFromSurface(Game::render_manager.get_renderer(), surface);
		SDL_DestroySurface(surface);
		SDL_GetTextureSize(texture, &position.w, &position.h);
	}

	void TextComponent::render()
	{
		SDL_RenderTexture(Game::render_manager.get_renderer(), texture, nullptr, &position);
	}
}
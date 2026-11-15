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

	void TextComponent::initialize()
	{
		renderer = Game::render_manager.get_renderer();
	}

	void TextComponent::set_text(const std::string& text, const unsigned int& font_family)
	{
		SDL_Surface* surface = nullptr;
		TTF_Font* font = Game::font_manager.get_font(font_family);

		if(font)
		{
			surface = TTF_RenderText_Blended(font, text.c_str(), 0, color);
		}

		if(renderer && surface)
		{
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_DestroySurface(surface);

			if(texture)
			{
				SDL_GetTextureSize(texture, &position.w, &position.h);
			}
		}
	}

	void TextComponent::render()
	{
		if(renderer && texture)
		{
			SDL_RenderTexture(renderer, texture, nullptr, &position);
		}
	}
}
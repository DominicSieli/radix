#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "font_manager.h"
#include "text_component.h"

namespace Radix
{
	TextComponent::TextComponent(const std::string& text, const unsigned int& font, const SDL_Color& color, const bool& fixed_position):
		text{text}, font{font}, color{color}, fixed_position{fixed_position}
	{}

	void TextComponent::initialize()
	{
		update_text();
		renderer = Game::render_manager.get_renderer();

		if(get_entity()->has_component<TransformComponent>())
		{
			transform_component = get_entity()->get_component<TransformComponent>();
		}

		if(transform_component)
		{
			rect.x = transform_component->get_position().x;
			rect.y = transform_component->get_position().y;
		}
	}

	void TextComponent::update(const float&)
	{
		SDL_FRect camera = Game::camera_manager.get_camera();

		rect.x = rect.x - ((fixed_position == true) ? 0.00f : camera.x);
		rect.y = rect.y - ((fixed_position == true) ? 0.00f : camera.y);
	}

	void TextComponent::render()
	{
		if(renderer && texture)
		{
			SDL_RenderTexture(renderer, texture, nullptr, &rect);
		}
	}

	void TextComponent::update_text()
	{
		SDL_Surface* surface = nullptr;
		TTF_Font* ttf_font = Game::font_manager.get_font(font);

		if(ttf_font)
		{
			surface = TTF_RenderText_Blended(ttf_font, text.c_str(), 0, color);
		}

		if(renderer && surface)
		{
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			SDL_DestroySurface(surface);

			if(texture)
			{
				SDL_GetTextureSize(texture, &rect.w, &rect.h);
			}
		}
	}

	void TextComponent::set_color(const SDL_Color& new_color)
	{
		color = new_color;
	}

	void TextComponent::set_text(const std::string& new_text)
	{
		text = new_text;
	}

	void TextComponent::set_font(const unsigned int& new_font)
	{
		font = new_font;
	}
}
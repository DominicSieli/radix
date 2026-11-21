#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "font_manager.h"
#include "text_component.h"

namespace Radix
{
	TextComponent::TextComponent(const std::string& text, const unsigned int& font, const SDL_Color& color, const SDL_FRect& sdl_frect, const bool& fixed_position):
		text{text}, font{font}, color{color}, sdl_frect{sdl_frect}, fixed_position{fixed_position}
	{}

	void TextComponent::initialize()
	{
		create_texture();
		renderer = Game::render_manager.get_renderer();
	}

	void TextComponent::update(const float&)
	{
		position = sdl_frect;
		SDL_FRect camera = Game::camera_manager.get_camera();

		position.x -= ((fixed_position == true) ? 0.00f : camera.x);
		position.y -= ((fixed_position == true) ? 0.00f : camera.y);
	}

	void TextComponent::render()
	{
		if(renderer && texture)
		{
			SDL_RenderTexture(renderer, texture, nullptr, &position);
		}
	}

	void TextComponent::create_texture()
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
				SDL_GetTextureSize(texture, &sdl_frect.w, &sdl_frect.h);
			}
		}
	}

	void TextComponent::set_text(const std::string& new_text)
	{
		text = new_text;
		create_texture();
	}

	void TextComponent::set_font(const unsigned int& new_font)
	{
		font = new_font;
		create_texture();
	}

	void TextComponent::set_color(const SDL_Color& new_color)
	{
		color = new_color;
		create_texture();
	}

	void TextComponent::set_position(const SDL_FRect& new_frect)
	{
		sdl_frect = new_frect;
	}
}
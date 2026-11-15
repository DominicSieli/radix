#include "font_manager.h"

namespace Radix
{
	FontManager::FontManager()
	{}

	FontManager::~FontManager()
	{
		destroy();
	}

	void FontManager::destroy()
	{
		clear_fonts();
	}

	void FontManager::clear_fonts()
	{
		for(auto& [id, font] : fonts)
		{
			TTF_CloseFont(font);
		}

		fonts.clear();
	}

	void FontManager::delete_font(const unsigned int& id)
	{
		TTF_CloseFont(fonts[id]);
		fonts.erase(id);
	}

	TTF_Font* FontManager::get_font(const unsigned int& id)
	{
		return fonts[id];
	}

	void FontManager::add_font(const unsigned int& id, const char* file_path, const float& size)
	{
		if(file_path)
		{
			fonts.try_emplace(id, TTF_OpenFont(file_path, size));
		}
	}
}
#include "font_manager.h"
#include "asset_manager.h"
#include "texture_manager.h"

namespace Radix
{
	AssetManager::AssetManager()
	{}

	AssetManager::~AssetManager()
	{
		clear_all();
	}

	void AssetManager::clear_all()
	{
		clear_fonts();
		clear_textures();
	}

	void AssetManager::clear_fonts()
	{
		for(auto& [id, font] : fonts)
		{
			FontManager::delete_font(font);
		}

		fonts.clear();
	}

	void AssetManager::clear_textures()
	{
		for(auto& [id, texture] : textures)
		{
			TextureManager::delete_texture(texture);
		}

		textures.clear();
	}

	void AssetManager::delete_font(const unsigned int& id)
	{
		FontManager::delete_font(fonts[id]);
	}

	void AssetManager::delete_texture(const unsigned int& id)
	{
		TextureManager::delete_texture(textures[id]);
	}

	TTF_Font* AssetManager::get_font(const unsigned int& id)
	{
		return fonts[id];
	}

	SDL_Texture* AssetManager::get_texture(const unsigned int& id)
	{
		return textures[id];
	}

	void AssetManager::add_texture(const unsigned int& id, const char* file_path)
	{
		textures.try_emplace(id, TextureManager::load_texture(file_path));
	}

	void AssetManager::add_font(const unsigned int& id, const char* file_path, const float& size)
	{
		fonts.try_emplace(id, FontManager::load_font(file_path, size));
	}
}
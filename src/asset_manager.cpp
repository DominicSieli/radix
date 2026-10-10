#include "asset_manager.h"
#include "font_manager.h"
#include "texture_manager.h"

namespace Radix
{
	AssetManager::AssetManager()
	{}

	AssetManager::~AssetManager()
	{
		clear();
	}

	void AssetManager::clear()
	{
		fonts.clear();
		textures.clear();
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
		if(!textures.contains(id))
		{
			textures.try_emplace(id, TextureManager::load_texture(file_path));
		}
	}

	void AssetManager::add_font(const unsigned int& id, const char* file_path, const float& size)
	{
		if(!fonts.contains(id))
		{
			fonts.try_emplace(id, FontManager::load_font(file_path, size));
		}
	}
}
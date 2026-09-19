#include "asset_manager.h"

namespace Radix
{
	AssetManager::AssetManager(EntityManager* entity_manager)
	{}

	AssetManager::~AssetManager()
	{}

	void AssetManager::clear()
	{
		fonts.clear();
		textures.clear();
	}

	TTF_Font* AssetManager::get_font(const unsigned int& font_id)
	{
		return fonts[font_id];
	}

	SDL_Texture* AssetManager::get_texture(const unsigned int& texture_id)
	{
		return textures[texture_id];
	}

	void AssetManager::add_texture(const unsigned int& texture_id, const char* file_path)
	{
		textures.emplace(texture_id, TextureManager::load_texture(file_path));
	}

	void AssetManager::add_font(const unsigned int& font_id, const char* file_path, int font_size)
	{
		fonts.emplace(font_id, FontManager::load_font(file_path, font_size));
	}
}
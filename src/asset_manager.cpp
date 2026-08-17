#include "asset_manager.h"

namespace radix
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

	SDL_Texture* AssetManager::get_texture(std::string texture_id)
	{
		return textures[texture_id];
	}

	void AssetManager::add_texture(std::string texture_id, const char* file_path)
	{
		textures.emplace(texture_id, TextureManager::load_texture(file_path));
	}

	TTF_Font* AssetManager::get_font(std::string font_id)
	{
		return fonts[font_id];
	}

	void AssetManager::add_font(std::string font_id, const char* file_path, int font_size)
	{
		fonts.emplace(font_id, FontManager::load_font(file_path, font_size));
	}
}
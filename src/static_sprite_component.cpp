#include "static_sprite_component.h"

namespace radix
{
	StaticSpriteComponent::StaticSpriteComponent()
	{}

	StaticSpriteComponent::StaticSpriteComponent(const char* file_path)
	{
		this->fixed = false;
		set_texture(file_path);
	}

	void StaticSpriteComponent::set_texture(std::string asset_texture_id)
	{
		texture = Game::asset_manager->get_texture(asset_texture_id);
	}

	void StaticSpriteComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		source.x = 0;
		source.y = 0;
		source.w = transform_component->dimension.x;
		source.h = transform_component->dimension.y;
	}

	void StaticSpriteComponent::update(float delta_time)
	{
		source.y = index * static_cast<int>(transform_component->dimension.y);

		destination.x = static_cast<int>(transform_component->position.x) - ((fixed == true) ? 0 : Game::camera.x);
		destination.y = static_cast<int>(transform_component->position.y) - ((fixed == true) ? 0 : Game::camera.y);
		destination.w = static_cast<int>(transform_component->dimension.x * transform_component->scale);
		destination.h = static_cast<int>(transform_component->dimension.y * transform_component->scale);
	}

	void StaticSpriteComponent::render()
	{
		TextureManager::draw(texture, source, destination, sprite_flip);
	}
}
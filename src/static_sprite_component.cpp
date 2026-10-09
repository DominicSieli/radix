#include "game.h"
#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent(const unsigned int& texture_id, const Vector2<float>& dimensions, const bool& fixed):
		texture_id{texture_id}, dimensions{dimensions}, fixed{fixed}
	{
		set_texture(texture_id);
	}

	void StaticSpriteComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();

		source.x = 0;
		source.y = 0;
		source.w = dimensions.x;
		source.h = dimensions.y;
	}

	void StaticSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}

	void StaticSpriteComponent::update(const float&)
	{
		destination.x = transform_component->position.x - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.x));
		destination.y = transform_component->position.y - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.y));
		destination.w = dimensions.x * transform_component->scale.x;
		destination.h = dimensions.y * transform_component->scale.y;
	}

	void StaticSpriteComponent::render()
	{
		TextureManager::draw(texture, source, destination, sprite_flip);
	}
}
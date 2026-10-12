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
		if(entity->has_component<TransformComponent>())
		{
			transform_component = entity->get_component<TransformComponent>();

			source.x = 0;
			source.y = 0;
			source.w = dimensions.x;
			source.h = dimensions.y;
		}
	}

	void StaticSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}

	void StaticSpriteComponent::update(const float&)
	{
		if(entity->has_component<TransformComponent>())
		{
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();

			destination.x = position.x - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.x));
			destination.y = position.y - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.y));
			destination.w = dimensions.x * scale.x;
			destination.h = dimensions.y * scale.y;
		}
	}

	void StaticSpriteComponent::render()
	{
		if(entity->has_component<TransformComponent>())
		{
			TextureManager::draw(texture, source, destination, transform_component->get_rotation(), sprite_flip);
		}
	}
}
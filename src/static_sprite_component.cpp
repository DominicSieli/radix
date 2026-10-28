#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent(const bool& fixed, const SDL_FlipMode& flip, const unsigned int& texture_id, const Vector2<float>& dimensions):
		fixed{fixed}, flip{flip}, texture_id{texture_id}, dimensions{dimensions}
	{
		set_texture(texture_id);
	}

	void StaticSpriteComponent::initialize()
	{
		source.x = 0;
		source.y = 0;
		source.w = dimensions.x;
		source.h = dimensions.y;
		transform_component = get_entity()->get_component<TransformComponent>();
	}

	void StaticSpriteComponent::update(const float&)
	{
		Vector2<float> scale = transform_component->get_scale();
		Vector2<float> position = transform_component->get_position();

		destination.w = dimensions.x * scale.x;
		destination.h = dimensions.y * scale.y;
		destination.x = position.x - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera_manager.get_camera().x));
		destination.y = position.y - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera_manager.get_camera().y));
	}

	void StaticSpriteComponent::render()
	{
		if(fixed || (!fixed && Game::camera_manager.is_inside_bounds(transform_component->get_position(), transform_component->get_dimensions())))
		{
			SDL_RenderTextureRotated(Game::render_manager.get_renderer(), texture, &source, &destination, transform_component->get_rotation(), nullptr, flip);
		}
	}

	void StaticSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}
}
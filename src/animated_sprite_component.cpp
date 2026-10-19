#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "constraints.h"
#include "asset_manager.h"
#include "animated_sprite_component.h"

namespace Radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent(const std::map<unsigned int, Animation>& animations, const unsigned int& texture_id, const unsigned int& default_animation, const Vector2<float>& dimensions, const bool& fixed):
		animations{animations}, texture_id{texture_id}, default_animation{default_animation}, current_animation{default_animation}, dimensions{dimensions}, fixed{fixed}
	{
		set_texture(texture_id);
		play(default_animation);
	}

	void AnimatedSpriteComponent::initialize()
	{
		source.x = 0;
		source.y = 0;
		source.w = dimensions.x;
		source.h = dimensions.y;
		transform_component = get_entity()->get_component<TransformComponent>();
	}

	void AnimatedSpriteComponent::update(const float&)
	{
		Vector2<float> scale = transform_component->get_scale();
		Vector2<float> position = transform_component->get_position();
		unsigned int speed = animations[current_animation].speed;
		unsigned int frames = animations[current_animation].frames;

		source.x = source.w * static_cast<float>((SDL_GetTicks() / speed) % frames);
		source.y = static_cast<float>(index) * dimensions.y;

		destination.x = position.x - ((fixed == true) ? 0.00f : Game::camera.x);
		destination.y = position.y - ((fixed == true) ? 0.00f : Game::camera.y);
		destination.w = dimensions.x * scale.x;
		destination.h = dimensions.y * scale.y;
	}

	void AnimatedSpriteComponent::render()
	{
		if(fixed == true || (fixed == false && inside_camera_bounds(transform_component->get_position(), transform_component->get_dimensions())))
		{
			SDL_RenderTextureRotated(Game::renderer, texture, &source, &destination, transform_component->get_rotation(), nullptr, sprite_flip);
		}
	}

	void AnimatedSpriteComponent::play(const unsigned int& animation)
	{
		current_animation = animation;
		index = animations[animation].index;
	}

	void AnimatedSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}
}
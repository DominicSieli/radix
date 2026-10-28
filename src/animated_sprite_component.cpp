#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "asset_manager.h"
#include "animated_sprite_component.h"

namespace Radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent(const bool& fixed, const SDL_FlipMode& flip, const unsigned int& texture_id, const Vector2<float>& dimensions, const unsigned int& default_animation, const std::unordered_map<unsigned int, Animation>& animations):
		fixed{fixed}, flip{flip}, texture_id{texture_id}, dimensions{dimensions}, default_animation{default_animation}, animations{animations}, current_animation{default_animation}
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
		if(!paused)
		{
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			unsigned int speed = animations[current_animation].speed;
			unsigned int frames = animations[current_animation].frames;

			source.x = source.w * static_cast<float>((SDL_GetTicks() / speed) % frames);
			source.y = static_cast<float>(index) * dimensions.y;

			destination.w = dimensions.x * scale.x;
			destination.h = dimensions.y * scale.y;
			destination.x = position.x - ((fixed == true) ? 0.00f : Game::camera_manager.get_camera().x);
			destination.y = position.y - ((fixed == true) ? 0.00f : Game::camera_manager.get_camera().y);
		}
	}

	void AnimatedSpriteComponent::render()
	{
		if(fixed || (!fixed && Game::camera_manager.is_inside_bounds(transform_component->get_position(), transform_component->get_dimensions())))
		{
			SDL_RenderTextureRotated(Game::render_manager.get_renderer(), texture, &source, &destination, transform_component->get_rotation(), nullptr, flip);
		}
	}

	void AnimatedSpriteComponent::pause()
	{
		paused = true;
	}

	void AnimatedSpriteComponent::unpause()
	{
		paused = false;
	}

	bool AnimatedSpriteComponent::is_paused()
	{
		return paused;
	}

	void AnimatedSpriteComponent::play(const unsigned int& animation)
	{
		current_animation = animation;
		index = animations[current_animation].index;
	}

	void AnimatedSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}
}
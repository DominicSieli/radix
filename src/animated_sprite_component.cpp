#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "asset_manager.h"
#include "animated_sprite_component.h"

namespace Radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent(const bool& fixed, const SDL_FlipMode& flip, const unsigned int& texture_id, const unsigned int& default_animation, const std::unordered_map<unsigned int, Animation>& animations):
		fixed{fixed}, flip{flip}, texture_id{texture_id}, default_animation{default_animation}, animations{animations}, current_animation{default_animation}
	{}

	void AnimatedSpriteComponent::initialize()
	{
		set_texture(texture_id);
		play(default_animation);
		renderer = Game::render_manager.get_renderer();
		transform_component = get_entity()->get_component<TransformComponent>();
	}

	void AnimatedSpriteComponent::update(const float&)
	{
		if(!paused)
		{
			SDL_FRect camera = Game::camera_manager.get_camera();
			unsigned int speed = animations[current_animation].speed;
			unsigned int frames = animations[current_animation].frames;
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();

			source.x = source.w * static_cast<float>((SDL_GetTicks() / speed) % frames);
			source.y = static_cast<float>(index) * dimensions.y;
			source.w = dimensions.x;
			source.h = dimensions.y;

			destination.w = dimensions.x * scale.x;
			destination.h = dimensions.y * scale.y;
			destination.x = position.x - ((fixed == true) ? 0.00f : camera.x);
			destination.y = position.y - ((fixed == true) ? 0.00f : camera.y);
		}
	}

	void AnimatedSpriteComponent::render()
	{
		if(renderer && texture && transform_component)
		{
			float rotation = transform_component->get_rotation();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();
			bool is_inside_camera_bounds = Game::camera_manager.is_inside_bounds(position, dimensions);

			if(fixed || (!fixed && is_inside_camera_bounds))
			{
				SDL_RenderTextureRotated(renderer, texture, &source, &destination, rotation, nullptr, flip);
			}
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
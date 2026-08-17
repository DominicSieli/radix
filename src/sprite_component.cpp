#include "sprite_component.h"

namespace radix
{
	SpriteComponent::SpriteComponent(const char* file_path)
	{
		this->animated = false;
		this->fixed = false;
		set_texture(file_path);
	}

	SpriteComponent::SpriteComponent(std::string id, unsigned int frames, unsigned int speed, bool directional, bool fixed)
	{
		this->animated = true;
		this->frames = frames;
		this->speed = speed;
		this->fixed = fixed;

		if(directional == true)
		{
			Animation up = Animation(3, frames, speed);
			Animation down = Animation(0, frames, speed);
			Animation left = Animation(2, frames, speed);
			Animation right = Animation(1, frames, speed);

			animations.emplace("UpAnimation", up);
			animations.emplace("DownAnimation", down);
			animations.emplace("LeftAnimation", left);
			animations.emplace("RightAnimation", right);

			this->index = 0;
			this->animation_name = "DownAnimation";
		}
		else
		{
			Animation single_animation = Animation(0, frames, speed);
			animations.emplace("SingleAnimation", single_animation);
			this->index = 0;
			this->animation_name = "SingleAnimation";
		}

		play(this->animation_name);
		set_texture(id);
	}

	void SpriteComponent::play(std::string animation_name)
	{
		frames = animations[animation_name].frames;
		index = animations[animation_name].index;
		speed = animations[animation_name].speed;
		this->animation_name = animation_name;
	}

	void SpriteComponent::set_texture(std::string asset_texture_id)
	{
		texture = Game::asset_manager->get_texture(asset_texture_id);
	}

	void SpriteComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		source.x = 0;
		source.y = 0;
		source.w = transform_component->dimension.x;
		source.h = transform_component->dimension.y;
	}

	void SpriteComponent::update(float delta_time)
	{
		if(animated == true)
		{
			source.x = source.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		source.y = index * static_cast<int>(transform_component->dimension.y);

		destination.x = static_cast<int>(transform_component->position.x) - ((fixed == true) ? 0 : Game::camera.x);
		destination.y = static_cast<int>(transform_component->position.y) - ((fixed == true) ? 0 : Game::camera.y);
		destination.w = static_cast<int>(transform_component->dimension.x * transform_component->scale);
		destination.h = static_cast<int>(transform_component->dimension.y * transform_component->scale);
	}

	void SpriteComponent::render()
	{
		TextureManager::draw(texture, source, destination, sprite_flip);
	}
}
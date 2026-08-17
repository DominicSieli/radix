#include "keyboard_component.h"

namespace radix
{
	KeyboardComponent::KeyboardComponent()
	{}

	KeyboardComponent::KeyboardComponent(std::string up_key, std::string down_key, std::string left_key, std::string right_key, std::string shoot_key)
	{
		this->up_key = sdl_keycode(up_key);
		this->down_key = sdl_keycode(down_key);
		this->left_key = sdl_keycode(left_key);
		this->right_key = sdl_keycode(right_key);
		this->shoot_key = sdl_keycode(shoot_key);
	}

	std::string KeyboardComponent::sdl_keycode(std::string key)
	{
		if(key.compare("up") == 0) return "1073741906";
		if(key.compare("down") == 0) return "1073741905";
		if(key.compare("left") == 0) return "1073741904";
		if(key.compare("right") == 0) return "1073741903";
		if(key.compare("space") == 0) return "32";

		return std::to_string(static_cast<int>(key[0]));
	}

	void KeyboardComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		sprite_component = entity->get_component<SpriteComponent>();
	}

	void KeyboardComponent::update(float delta_time)
	{
		if(Game::event.type == SDL_KEYDOWN)
		{
			int speed = 100;
			std::string key_code = std::to_string(Game::event.key.keysym.sym);

			if(key_code.compare(up_key) == 0)
			{
				transform_component->velocity.x = 0;
				transform_component->velocity.y = -speed;
				sprite_component->play("UpAnimation");
			}

			if(key_code.compare(down_key) == 0)
			{
				transform_component->velocity.x = 0;
				transform_component->velocity.y = speed;
				sprite_component->play("DownAnimation");
			}

			if(key_code.compare(left_key) == 0)
			{
				transform_component->velocity.x = -speed;
				transform_component->velocity.y = 0;
				sprite_component->play("LeftAnimation");
			}

			if(key_code.compare(right_key) == 0)
			{
				transform_component->velocity.x = speed;
				transform_component->velocity.y = 0;
				sprite_component->play("RightAnimation");
			}

			if(key_code.compare(shoot_key) == 0)
			{}
		}

		if(Game::event.type == SDL_KEYUP)
		{
			std::string key_code = std::to_string(Game::event.key.keysym.sym);

			if(key_code.compare(up_key) == 0)
			{
				transform_component->velocity.y = 0;
			}

			if(key_code.compare(down_key) == 0)
			{
				transform_component->velocity.y = 0;
			}

			if(key_code.compare(left_key) == 0)
			{
				transform_component->velocity.x = 0;
			}

			if(key_code.compare(right_key) == 0)
			{
				transform_component->velocity.x = 0;
			}

			if(key_code.compare(shoot_key) == 0)
			{}
		}
	}
}
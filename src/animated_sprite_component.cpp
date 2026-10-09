#include "game.h"
#include "asset_manager.h"
#include "animated_sprite_component.h"

namespace Radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent(const std::map<unsigned int, Animation>& animations, const unsigned int& texture_id, const unsigned int& default_animation, const Vector2<int>& dimensions, const bool& fixed):
		animations{animations}, texture_id{texture_id}, default_animation{default_animation}, current_animation{default_animation}, dimensions{dimensions}, fixed{fixed}
	{
		set_texture(texture_id);
		play(default_animation);
	}

	void AnimatedSpriteComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();

		source.x = 0;
		source.y = 0;
		source.w = static_cast<float>(dimensions.x);
		source.h = static_cast<float>(dimensions.y);
	}

	void AnimatedSpriteComponent::update(const float&)
	{
		source.x = source.w * static_cast<float>((SDL_GetTicks() / animations[current_animation].speed) % animations[current_animation].frames);
		source.y = static_cast<float>(index * dimensions.y);

		destination.x = transform_component->position.x - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.x));
		destination.y = transform_component->position.y - ((fixed == true) ? 0.00f : static_cast<float>(Game::camera.y));
		destination.w = static_cast<float>(dimensions.x) * transform_component->scale.x;
		destination.h = static_cast<float>(dimensions.y) * transform_component->scale.y;
	}

	void AnimatedSpriteComponent::render()
	{
		TextureManager::draw(texture, source, destination, sprite_flip);
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
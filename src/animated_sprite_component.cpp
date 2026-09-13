#include "animated_sprite_component.h"

namespace radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent()
	{}

	AnimatedSpriteComponent::AnimatedSpriteComponent(std::string id, std::map<std::string, Animation>* animations, std::string default_animation, bool directional, bool fixed)
	{
		this->index = 0;
		this->fixed = fixed;
		this->animations = animations;
		this->current_animation = default_animation;
		play(this->current_animation);
		set_texture(id);
	}

	void AnimatedSpriteComponent::play(std::string current_animation)
	{
		this->index = (*animations)[current_animation].index;
		this->current_animation = current_animation;
	}

	void AnimatedSpriteComponent::set_texture(std::string asset_texture_id)
	{
		texture = Game::asset_manager->get_texture(asset_texture_id);
	}

	void AnimatedSpriteComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		source.x = 0;
		source.y = 0;
		source.w = transform_component->dimension.x;
		source.h = transform_component->dimension.y;
	}

	void AnimatedSpriteComponent::update(float delta_time)
	{
		source.x = source.w * static_cast<int>((SDL_GetTicks() / (*animations)[current_animation].speed) % (*animations)[current_animation].frames);
		source.y = index * static_cast<int>(transform_component->dimension.y);

		destination.x = static_cast<int>(transform_component->position.x) - ((fixed == true) ? 0 : Game::camera.x);
		destination.y = static_cast<int>(transform_component->position.y) - ((fixed == true) ? 0 : Game::camera.y);
		destination.w = static_cast<int>(transform_component->dimension.x * transform_component->scale);
		destination.h = static_cast<int>(transform_component->dimension.y * transform_component->scale);
	}

	void AnimatedSpriteComponent::render()
	{
		TextureManager::draw(texture, source, destination, sprite_flip);
	}
}
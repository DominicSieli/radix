#include "asset_manager.h"
#include "animated_sprite_component.h"

namespace Radix
{
	AnimatedSpriteComponent::AnimatedSpriteComponent()
	{}

	AnimatedSpriteComponent::AnimatedSpriteComponent(const std::map<unsigned int, Animation>& animations, unsigned int texture_id, unsigned int default_animation, bool fixed)
		: animations{animations}, default_animation{default_animation}, current_animation{default_animation}, fixed{fixed}
	{
		this->set_texture(texture_id);
		this->play(default_animation);
	}

	AnimatedSpriteComponent::~AnimatedSpriteComponent()
	{}

	void AnimatedSpriteComponent::initialize()
	{
		this->transform_component = this->entity->get_component<TransformComponent>();

		this->source.x = 0;
		this->source.y = 0;
		this->source.w = this->transform_component->dimension.x;
		this->source.h = this->transform_component->dimension.y;
	}

	void AnimatedSpriteComponent::update(float delta_time)
	{
		this->source.x = this->source.w * static_cast<int>((SDL_GetTicks() / this->animations[this->current_animation].speed) % this->animations[this->current_animation].frames);
		this->source.y = this->index * static_cast<int>(this->transform_component->dimension.y);

		this->destination.x = static_cast<int>(this->transform_component->position.x) - ((this->fixed == true) ? 0 : Game::camera.x);
		this->destination.y = static_cast<int>(this->transform_component->position.y) - ((this->fixed == true) ? 0 : Game::camera.y);
		this->destination.w = static_cast<int>(this->transform_component->dimension.x * this->transform_component->scale);
		this->destination.h = static_cast<int>(this->transform_component->dimension.y * this->transform_component->scale);
	}

	void AnimatedSpriteComponent::render()
	{
		TextureManager::draw(this->texture, this->source, this->destination, this->sprite_flip);
	}

	void AnimatedSpriteComponent::play(unsigned int animation)
	{
		this->current_animation = animation;
		this->index = this->animations[animation].index;
	}

	void AnimatedSpriteComponent::set_texture(unsigned int texture_id)
	{
		this->texture = Game::asset_manager.get_texture(texture_id);
	}
}
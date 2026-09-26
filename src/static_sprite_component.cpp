#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent()
	{}

	StaticSpriteComponent::~StaticSpriteComponent()
	{}

	StaticSpriteComponent::StaticSpriteComponent(unsigned int texture_id, bool fixed)
		: fixed{fixed}
	{
		this->set_texture(texture_id);
	}

	void StaticSpriteComponent::initialize()
	{
		this->transform_component = this->entity->get_component<TransformComponent>();

		this->source.x = 0;
		this->source.y = 0;
		this->source.w = this->transform_component->dimensions.x;
		this->source.h = this->transform_component->dimensions.y;
	}

	void StaticSpriteComponent::set_texture(unsigned int texture_id)
	{
		this->texture = Game::asset_manager.get_texture(texture_id);
	}

	void StaticSpriteComponent::update(double delta_time)
	{
		this->destination.x = static_cast<int>(this->transform_component->position.x) - ((this->fixed == true) ? 0 : Game::camera.x);
		this->destination.y = static_cast<int>(this->transform_component->position.y) - ((this->fixed == true) ? 0 : Game::camera.y);
		this->destination.w = static_cast<int>(this->transform_component->dimensions.x * this->transform_component->scale.x);
		this->destination.h = static_cast<int>(this->transform_component->dimensions.y * this->transform_component->scale.y);
	}

	void StaticSpriteComponent::render()
	{
		TextureManager::draw(this->texture, this->source, this->destination, this->sprite_flip);
	}
}
#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent()
	{}

	StaticSpriteComponent::~StaticSpriteComponent()
	{}

	StaticSpriteComponent::StaticSpriteComponent(unsigned int texture_id, Vector2<float> dimensions, bool fixed)
		: dimensions{dimensions}, fixed{fixed}
	{
		this->set_texture(texture_id);
	}

	void StaticSpriteComponent::initialize()
	{
		this->transform_component = this->entity->get_component<TransformComponent>();

		this->source.x = 0;
		this->source.y = 0;
		this->source.w = this->dimensions.x;
		this->source.h = this->dimensions.y;
	}

	void StaticSpriteComponent::set_texture(unsigned int texture_id)
	{
		this->texture = Game::asset_manager.get_texture(texture_id);
	}

	void StaticSpriteComponent::update(float delta_time)
	{
		this->destination.x = this->transform_component->position.x - ((this->fixed == true) ? 0.00f : static_cast<float>(Game::camera.x));
		this->destination.y = this->transform_component->position.y - ((this->fixed == true) ? 0.00f : static_cast<float>(Game::camera.y));
		this->destination.w = this->dimensions.x * this->transform_component->scale.x;
		this->destination.h = this->dimensions.y * this->transform_component->scale.y;
	}

	void StaticSpriteComponent::render()
	{
		TextureManager::draw(this->texture, this->source, this->destination, this->sprite_flip);
	}
}
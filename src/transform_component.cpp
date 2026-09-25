#include "transform_component.h"

namespace Radix
{
	TransformComponent::TransformComponent()
	{}

	TransformComponent::~TransformComponent()
	{}

	TransformComponent::TransformComponent(Vector2 position, Vector2 velocity, Vector2 dimension, float rotation, float scale)
		:position{position}, velocity{velocity}, dimension{dimension}, rotation{rotation}, scale{scale}
	{}

	void TransformComponent::initialize()
	{}

	void TransformComponent::update(float delta_time)
	{
		position.x += velocity.x * delta_time;
		position.y += velocity.y * delta_time;
	}

	void TransformComponent::render()
	{}
}
#include <cmath>

#include "vector_2.h"
#include "spawner_component.h"

namespace Radix
{
	SpawnerComponent::SpawnerComponent()
	{}

	SpawnerComponent::~SpawnerComponent()
	{}

	SpawnerComponent::SpawnerComponent(unsigned int speed, unsigned int degree, unsigned int range, bool loop)
		: speed{speed}, degree{degree}, range{range}, loop{loop}
	{
		this->radian = this->degree * std::numbers::pi_v<float> / 180.0f;
	}

	void SpawnerComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		origin = Vector2(transform_component->position.x, transform_component->position.y);
		transform_component->velocity = Vector2(std::cos(radian) * speed, std::sin(radian) * speed);
	}

	void SpawnerComponent::update(float delta_time)
	{
		if(Vector2::distance(transform_component->position, origin) > range)
		{
			if(loop == true)
			{
				transform_component->position.x = origin.x;
				transform_component->position.y = origin.y;
			}
			else
			{
				entity->destroy();
			}
		}
	}
}
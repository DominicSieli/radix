#include <cmath>
#include "projectile_emitter_component.h"

namespace radix
{
	ProjectileEmitterComponent::ProjectileEmitterComponent(int speed, int degree, int range, bool loop)
	{
		this->speed = speed;
		this->radian = degree * std::numbers::pi_v<float> / 180.0f;
		this->range = range;
		this->loop = loop;
	}

	void ProjectileEmitterComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		origin = create_vector2(transform_component->position.x, transform_component->position.y);
		transform_component->velocity = create_vector2(std::cos(radian) * speed, std::sin(radian) * speed);
	}

	void ProjectileEmitterComponent::update(float delta_time)
	{
		if(distance(transform_component->position, origin) > range)
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
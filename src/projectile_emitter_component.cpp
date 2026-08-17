#include "projectile_emitter_component.h"

namespace radix
{
	ProjectileEmitterComponent::ProjectileEmitterComponent(int speed, int degree, int range, bool loop)
	{
		this->speed = speed;
		this->radian = glm::radians(static_cast<float>(degree));
		this->range = range;
		this->loop = loop;
	}

	void ProjectileEmitterComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
		origin = glm::vec2(transform_component->position.x, transform_component->position.y);
		transform_component->velocity = glm::vec2(glm::cos(radian) * speed, glm::sin(radian) * speed);
	}

	void ProjectileEmitterComponent::update(float delta_time)
	{
		if(glm::distance(transform_component->position, origin) > range)
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
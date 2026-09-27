#include "spawner_component.h"

namespace Radix
{
	SpawnerComponent::SpawnerComponent()
	{}

	SpawnerComponent::~SpawnerComponent()
	{}

	SpawnerComponent::SpawnerComponent(float range, bool loop)
		: range{range}, loop{loop}
	{}

	void SpawnerComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
	}

	void SpawnerComponent::update(float delta_time)
	{}
}
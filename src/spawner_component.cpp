#include "spawner_component.h"

namespace Radix
{
	SpawnerComponent::SpawnerComponent()
	{}

	SpawnerComponent::~SpawnerComponent()
	{}

	SpawnerComponent::SpawnerComponent(double range, bool loop)
		: range{range}, loop{loop}
	{}

	void SpawnerComponent::initialize()
	{
		transform_component = entity->get_component<TransformComponent>();
	}

	void SpawnerComponent::update(double delta_time)
	{}
}
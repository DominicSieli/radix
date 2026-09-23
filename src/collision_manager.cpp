#include "entity.h"
#include "collision_manager.h"
#include "collider_component.h"

namespace Radix
{
	CollisionManager::CollisionManager()
	{}

	CollisionManager::~CollisionManager()
	{}

	unsigned int CollisionManager::check_collisions(const std::vector<Collision>& collisions, unsigned int no_collision)
	{
		for(int i = 0; i < Game::entity_manager.entities.size() - 1; i++)
		{
			Entity* entity_1 = Game::entity_manager.entities[i];

			if(entity_1->has_component<ColliderComponent>() == true)
			{
				ColliderComponent* entity_1_collider = entity_1->get_component<ColliderComponent>();

				for(int j = i + 1; j < Game::entity_manager.entities.size(); j++)
				{
					Entity* entity_2 = Game::entity_manager.entities[j];

					if(entity_1->name.compare(entity_2->name) != 0 && entity_2->has_component<ColliderComponent>() == true)
					{
						ColliderComponent* entity_2_collider = entity_2->get_component<ColliderComponent>();

						if(check_rect_collision(entity_1_collider->collider, entity_2_collider->collider) == true)
						{
							for(Collision collision : collisions)
							{
								if(entity_1_collider->tag == collision.collider_tag_1 && entity_2_collider->tag == collision.collider_tag_2)
								{
									return collision.collision_type;
								}
							}
						}
					}
				}
			}
		}

		return no_collision;
	}

	bool CollisionManager::check_rect_collision(SDL_Rect rect_1, SDL_Rect rect_2)
	{
		return (rect_1.x + rect_1.w >= rect_2.x && rect_2.x + rect_2.w >= rect_1.x && rect_1.y + rect_1.h >= rect_2.y && rect_2.y + rect_2.h >= rect_1.y);
	}
}
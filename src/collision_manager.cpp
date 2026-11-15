#include <cfloat>
#include <algorithm>

#include "game.h"
#include "entity.h"
#include "collision_manager.h"
#include "polygon_rect_component.h"

namespace Radix
{
	CollisionManager::CollisionManager()
	{}

	unsigned int CollisionManager::check_geometry_collisions(const std::vector<Collision>& collisions, const unsigned int& no_collision)
	{
		for(unsigned int i = 0; i < Game::entity_manager.get_entities().size() - 1; ++i)
		{
			Entity* entity_1 = Game::entity_manager.get_entities().at(i);

			if(entity_1 && entity_1->has_component<PolygonRectComponent>())
			{
				PolygonRectComponent* entity_1_geometry = entity_1->get_component<PolygonRectComponent>();

				for(unsigned int j = i + 1; j < Game::entity_manager.get_entities().size(); ++j)
				{
					Entity* entity_2 = Game::entity_manager.get_entities().at(j);

					if(entity_2 && entity_2->has_component<PolygonRectComponent>())
					{
						if(entity_1->get_id() != entity_2->get_id())
						{
							PolygonRectComponent* entity_2_geometry = entity_2->get_component<PolygonRectComponent>();

							if(check_geometry_collision(entity_1_geometry->get_geometry(), entity_2_geometry->get_geometry()))
							{
								for(const Collision& collision : collisions)
								{
									if(entity_1_geometry->get_tag() == collision.get_collider_tag_1() && entity_2_geometry->get_tag() == collision.get_collider_tag_2())
									{
										return collision.get_collision_type();
									}
								}
							}
						}
					}
				}
			}
		}

		return no_collision;
	}

	bool CollisionManager::check_geometry_collision(const std::vector<SDL_FPoint>& geometry_1, const std::vector<SDL_FPoint>& geometry_2)
	{
		if(geometry_1.size() < 3 || geometry_2.size() < 3)
		{
			return false;
		}

		if(!check_axes(geometry_1, geometry_2))
		{
			return false;
		}

		if(!check_axes(geometry_2, geometry_1))
		{
			return false;
		}

		return true;
	}


	bool CollisionManager::check_axes(const std::vector<SDL_FPoint>& geometry_1, const std::vector<SDL_FPoint>& geometry_2)
	{
		for(unsigned int i = 0; i < geometry_1.size(); ++i)
		{
			SDL_FPoint point_1 = geometry_1.at(i);
			SDL_FPoint point_2 = geometry_1.at((i + 1) % geometry_1.size());

			float edge_x = point_2.x - point_1.x;
			float edge_y = point_2.y - point_1.y;

			float axis_x = -edge_y;
			float axis_y = edge_x;

			float min_a = FLT_MAX;
			float max_a = -FLT_MAX;

			for(const SDL_FPoint& point : geometry_1)
			{
				float projection = point.x * axis_x + point.y * axis_y;

				min_a = std::min(min_a, projection);
				max_a = std::max(max_a, projection);
			}

			float min_b = FLT_MAX;
			float max_b = -FLT_MAX;

			for(const SDL_FPoint& point : geometry_2)
			{
				float projection = point.x * axis_x + point.y * axis_y;

				min_b = std::min(min_b, projection);
				max_b = std::max(max_b, projection);
			}

			if(max_a < min_b || max_b < min_a)
			{
				return false;
			}
		}

		return true;
	}
}
#include <cfloat>
#include <algorithm>

#include "game.h"
#include "entity.h"
#include "collision_manager.h"
#include "collider_component.h"
#include "polygon_rect_component.h"

namespace Radix
{
	CollisionManager::CollisionManager()
	{}

	unsigned int CollisionManager::check_rect_collisions(const std::vector<Collision>& collisions, const unsigned int& no_collision)
	{
		for(unsigned int i = 0; i < Game::entity_manager.get_entities().size() - 1; ++i)
		{
			Entity* entity_1 = Game::entity_manager.get_entities().at(i);

			if(entity_1->has_component<ColliderComponent>())
			{
				ColliderComponent* entity_1_collider = entity_1->get_component<ColliderComponent>();

				for(unsigned int j = i + 1; j < Game::entity_manager.get_entities().size(); ++j)
				{
					Entity* entity_2 = Game::entity_manager.get_entities().at(j);

					if(entity_1->get_type_id() != entity_2->get_type_id() && entity_2->has_component<ColliderComponent>())
					{
						ColliderComponent* entity_2_collider = entity_2->get_component<ColliderComponent>();

						if(check_rect_collision(entity_1_collider->get_collider(), entity_2_collider->get_collider()))
						{
							for(const Collision& collision : collisions)
							{
								if(entity_1_collider->get_tag() == collision.get_collider_tag_1() && entity_2_collider->get_tag() == collision.get_collider_tag_2())
								{
									return collision.get_collision_type();
								}
							}
						}
					}
				}
			}
		}

		return no_collision;
	}

	unsigned int CollisionManager::check_geometry_collisions(const std::vector<Collision>& collisions, const unsigned int& no_collision)
	{
		for(unsigned int i = 0; i < Game::entity_manager.get_entities().size() - 1; ++i)
		{
			Entity* entity_1 = Game::entity_manager.get_entities().at(i);

			if(entity_1->has_component<PolygonRectComponent>())
			{
				PolygonRectComponent* entity_1_geometry = entity_1->get_component<PolygonRectComponent>();

				for(unsigned int j = i + 1; j < Game::entity_manager.get_entities().size(); ++j)
				{
					Entity* entity_2 = Game::entity_manager.get_entities().at(j);

					if(entity_1->get_type_id() != entity_2->get_type_id() && entity_2->has_component<PolygonRectComponent>())
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

		return no_collision;
	}

	bool CollisionManager::check_rect_collision(const SDL_FRect& rect_1, const SDL_FRect& rect_2)
	{
		return (rect_1.x + rect_1.w >= rect_2.x && rect_2.x + rect_2.w >= rect_1.x && rect_1.y + rect_1.h >= rect_2.y && rect_2.y + rect_2.h >= rect_1.y);
	}

	bool CollisionManager::check_geometry_collision(const std::vector<SDL_FPoint>& geometry_1, const std::vector<SDL_FPoint>& geometry_2)
	{
		// Test the edges of both polygons.
		auto check_axes = [](const std::vector<SDL_FPoint>& geometry_a, const std::vector<SDL_FPoint>& geometry_b) -> bool
		{
			for(size_t i = 0; i < geometry_a.size(); ++i)
			{
				// Get the current edge.
				SDL_FPoint point_1 = geometry_a.at(i);
				SDL_FPoint point_2 = geometry_a.at((i + 1) % geometry_a.size());

				float edge_x = point_2.x - point_1.x;
				float edge_y = point_2.y - point_1.y;

				// Calculate perpendicular axis (normal).
				float axis_x = -edge_y;
				float axis_y = edge_x;

				// Project polygon 1 onto the axis.
				float min_a = FLT_MAX;
				float max_a = -FLT_MAX;

				for(const SDL_FPoint& point : geometry_a)
				{
					float projection = point.x * axis_x + point.y * axis_y;

					min_a = std::min(min_a, projection);
					max_a = std::max(max_a, projection);
				}

				// Project polygon 2 onto the axis.
				float min_b = FLT_MAX;
				float max_b = -FLT_MAX;

				for(const SDL_FPoint& point : geometry_b)
				{
					float projection = point.x * axis_x + point.y * axis_y;

					min_b = std::min(min_b, projection);
					max_b = std::max(max_b, projection);
				}

				// Check for a separating axis.
				if(max_a < min_b || max_b < min_a)
				{
					return false;
				}
			}

			return true;
		};

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
}
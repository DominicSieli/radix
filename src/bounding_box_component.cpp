#include "game.h"
#include "vectors.h"
#include "geometry.h"
#include "bounding_box_component.h"

namespace Radix
{
	BoundingBoxComponent::BoundingBoxComponent(const unsigned int& tag):
		tag{tag}
	{}

	void BoundingBoxComponent::initialize()
	{
		renderer = Game::render_manager.get_renderer();

		if(get_entity()->has_component<TransformComponent>())
		{
			transform_component = get_entity()->get_component<TransformComponent>();
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();

			vertices.push_back({position.x, position.y});
			vertices.push_back({position.x + (dimensions.x * scale.x), position.y});
			vertices.push_back({position.x + (dimensions.x * scale.x), position.y + (dimensions.y * scale.y)});
			vertices.push_back({position.x, position.y + (dimensions.y * scale.y)});
		}
	}

	void BoundingBoxComponent::update(const float&)
	{
		if(transform_component)
		{
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();
			Vector2<float> center = Vector2<float>(position.x + ((dimensions.x * scale.x) / 2), position.y + ((dimensions.y * scale.y) / 2));

			position.x = position.x - Game::camera_manager.get_camera().x;
			position.y = position.y - Game::camera_manager.get_camera().y;

			vertices.at(0) = {position.x, position.y};
			vertices.at(1) = {position.x + (dimensions.x * scale.x), position.y};
			vertices.at(2) = {position.x + (dimensions.x * scale.x), position.y + (dimensions.y * scale.y)};
			vertices.at(3) = {position.x, position.y + (dimensions.y * scale.y)};
		}
	}

	void BoundingBoxComponent::render()
	{
		render_polygons(renderer, vertices);
	}

	unsigned int BoundingBoxComponent::get_tag()
	{
		return tag;
	}

	std::vector<SDL_FPoint> BoundingBoxComponent::get_vertices()
	{
		return vertices;
	}
}

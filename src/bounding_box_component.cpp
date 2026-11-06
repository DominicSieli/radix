#include "game.h"
#include "vectors.h"
#include "geometry.h"
#include "bounding_box_component.h"

namespace Radix
{
	BoundingBoxComponent::BoundingBoxComponent(const unsigned int& tag, const SDL_Color& color):
		tag{tag}, color{color}
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

			geometry.push_back({position.x, position.y});
			geometry.push_back({position.x + (dimensions.x * scale.x), position.y});
			geometry.push_back({position.x + (dimensions.x * scale.x), position.y + (dimensions.y * scale.y)});
			geometry.push_back({position.x, position.y + (dimensions.y * scale.y)});
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

			geometry.at(0) = {position.x, position.y};
			geometry.at(1) = {position.x + (dimensions.x * scale.x), position.y};
			geometry.at(2) = {position.x + (dimensions.x * scale.x), position.y + (dimensions.y * scale.y)};
			geometry.at(3) = {position.x, position.y + (dimensions.y * scale.y)};
		}
	}

	void BoundingBoxComponent::render()
	{
		render_geometry(renderer, geometry, color);
	}

	unsigned int BoundingBoxComponent::get_tag()
	{
		return tag;
	}

	void BoundingBoxComponent::set_color(const SDL_Color& new_color)
	{
		color = new_color;
	}

	std::vector<SDL_FPoint> BoundingBoxComponent::get_geometry()
	{
		return geometry;
	}
}

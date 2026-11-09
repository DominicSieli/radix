#include "game.h"
#include "vectors.h"
#include "geometry.h"
#include "polygon_rect_component.h"

namespace Radix
{
	PolygonRectComponent::PolygonRectComponent(const unsigned int& tag, const SDL_Color& color, const bool& render_lines):
		tag{tag}, color{color}, render_lines{render_lines}
	{}

	void PolygonRectComponent::initialize()
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

	void PolygonRectComponent::update(const float&)
	{
		if(transform_component)
		{
			float rotation = transform_component->get_rotation();
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();

			position.x = position.x - Game::camera_manager.get_camera().x;
			position.y = position.y - Game::camera_manager.get_camera().y;

			vertices.at(0) = {position.x, position.y};
			vertices.at(1) = {position.x + (dimensions.x * scale.x), position.y};
			vertices.at(2) = {position.x + (dimensions.x * scale.x), position.y + (dimensions.y * scale.y)};
			vertices.at(3) = {position.x, position.y + (dimensions.y * scale.y)};

			scale_geometry(vertices, scale.x, scale.y);
			rotate_geometry(vertices, rotation);
		}
	}

	void PolygonRectComponent::render()
	{
		if(render_lines)
		{
			render_geometry(renderer, vertices, color);
		}
	}

	unsigned int PolygonRectComponent::get_tag()
	{
		return tag;
	}

	void PolygonRectComponent::set_color(const SDL_Color& new_color)
	{
		color = new_color;
	}

	const std::vector<SDL_FPoint>& PolygonRectComponent::get_geometry()
	{
		return vertices;
	}
}

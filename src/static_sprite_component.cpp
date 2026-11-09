#include <array>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "vectors.h"
#include "asset_manager.h"
#include "static_sprite_component.h"

namespace Radix
{
	StaticSpriteComponent::StaticSpriteComponent(const bool& fixed, const SDL_FlipMode& flip, const unsigned int& texture_id):
		fixed{fixed}, flip{flip}, texture_id{texture_id}
	{}

	void StaticSpriteComponent::initialize()
	{
		set_texture(texture_id);
		renderer = Game::render_manager.get_renderer();
		transform_component = get_entity()->get_component<TransformComponent>();
		polygon_rect_component = get_entity()->get_component<PolygonRectComponent>();
	}

	void StaticSpriteComponent::update(const float&)
	{
		if(transform_component)
		{
			SDL_FRect camera = Game::camera_manager.get_camera();
			Vector2<float> scale = transform_component->get_scale();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();

			source.x = 0;
			source.y = 0;
			source.w = dimensions.x;
			source.h = dimensions.y;

			destination.w = dimensions.x * scale.x;
			destination.h = dimensions.y * scale.y;
			destination.x = position.x - ((fixed == true) ? 0.00f : camera.x);
			destination.y = position.y - ((fixed == true) ? 0.00f : camera.y);
		}
	}

	void StaticSpriteComponent::render()
	{
		if(renderer && texture && transform_component)
		{
			float rotation = transform_component->get_rotation();
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();
			bool is_inside_camera_bounds = Game::camera_manager.is_inside_bounds(position, dimensions);
			std::vector<SDL_FPoint> polygon_rect_vertices = polygon_rect_component->get_geometry();

			if(fixed || (!fixed && is_inside_camera_bounds))
			{
				//render_geometry(renderer, texture, polygon_rect_vertices);
				SDL_RenderTextureRotated(renderer, texture, &source, &destination, rotation, nullptr, flip);
			}
		}
	}

	void StaticSpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}

	void StaticSpriteComponent::render_geometry(SDL_Renderer* renderer, SDL_Texture* texture, const std::vector<SDL_FPoint>& positions)
	{
		std::array<SDL_Vertex, 4> vertices;

		constexpr std::array<int, 6> indices = {
			0, 1, 2,
			0, 2, 3
		};

		constexpr std::array<SDL_FPoint, 4> uvs = {{
			{0.0f, 0.0f},
			{1.0f, 0.0f},
			{1.0f, 1.0f},
			{0.0f, 1.0f}
		}};

		for(unsigned int i = 0; i < vertices.size(); ++i)
		{
			vertices.at(i).position = positions.at(i);
			vertices.at(i).tex_coord = uvs.at(i);
			vertices.at(i).color = {1.0f, 1.0f, 1.0f, 1.0f};
		}

		SDL_RenderGeometry(renderer, texture, vertices.data(), static_cast<int>(vertices.size()), indices.data(), static_cast<int>(indices.size()));
	}
}
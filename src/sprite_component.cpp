#include <array>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"
#include "asset_manager.h"
#include "sprite_component.h"

namespace Radix
{
	SpriteComponent::SpriteComponent(const unsigned int& texture_id):
		texture_id{texture_id}
	{}

	SpriteComponent::SpriteComponent(const unsigned int& texture_id, const unsigned int& default_animation, std::unordered_map<unsigned int, Animation> animations):
		texture_id{texture_id}, default_animation{default_animation}, animations{animations}, current_animation{default_animation}
	{}

	void SpriteComponent::initialize()
	{
		set_texture(texture_id);
		renderer = Game::render_manager.get_renderer();
		transform_component = get_entity()->get_component<TransformComponent>();
		polygon_rect_component = get_entity()->get_component<PolygonRectComponent>();

		if(!animations.empty())
		{
			play(default_animation);
		}
	}

	void SpriteComponent::update(const float& delta_time)
	{
		if(transform_component && !paused)
		{
			if(animations.empty())
			{
				Vector2<float> dimensions = transform_component->get_dimensions();

				source.x = 0;
				source.y = 0;
				source.w = dimensions.x;
				source.h = dimensions.y;
			}

			if(!animations.empty())
			{
				unsigned int frames = animations[current_animation].frames;
				Vector2<float> dimensions = transform_component->get_dimensions();
				float speed = static_cast<float>(animations[current_animation].speed);

				animation_progress += speed * delta_time;

				while(animation_progress >= 1.0f)
				{
					animation_progress -= 1.0f;
					current_frame = (current_frame + 1) % frames;
				}

				source.x = source.w * static_cast<float>(current_frame);
				source.y = static_cast<float>(index) * dimensions.y;
				source.w = dimensions.x;
				source.h = dimensions.y;
			}
		}
	}

	void SpriteComponent::render()
	{
		if(renderer && texture && transform_component)
		{
			Vector2<float> position = transform_component->get_position();
			Vector2<float> dimensions = transform_component->get_dimensions();
			bool is_inside_camera_bounds = Game::camera_manager.is_inside_bounds(position, dimensions);
			std::vector<SDL_FPoint> polygon_rect_vertices = polygon_rect_component->get_geometry();
			bool fixed_position = polygon_rect_component->is_fixed_position();

			if(fixed_position || (!fixed_position && is_inside_camera_bounds))
			{
				render_geometry(renderer, texture, polygon_rect_vertices);
			}
		}
	}

	void SpriteComponent::pause()
	{
		paused = true;
	}

	void SpriteComponent::unpause()
	{
		paused = false;
	}

	bool SpriteComponent::is_paused()
	{
		return paused;
	}

	void SpriteComponent::play(const unsigned int& animation)
	{
		current_animation = animation;
		index = animations[current_animation].index;
	}

	void SpriteComponent::set_texture(const unsigned int& id)
	{
		texture = Game::asset_manager.get_texture(id);
	}

	void SpriteComponent::render_geometry(SDL_Renderer* renderer, SDL_Texture* texture, const std::vector<SDL_FPoint>& positions)
	{
		float texture_width;
		float texture_hight;
		std::array<SDL_Vertex, 4> vertices;

		SDL_GetTextureSize(texture, &texture_width, &texture_hight);

		constexpr std::array<int, 6> indices = {
			0, 1, 2,
			0, 2, 3
		};

		float u1 = source.x / texture_width;
		float v1 = source.y / texture_hight;
		float u2 = (source.x + source.w) / texture_width;
		float v2 = (source.y + source.h) / texture_hight;

		std::array<SDL_FPoint, 4> uvs = {{
			{u1, v1},
			{u2, v1},
			{u2, v2},
			{u1, v2}
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
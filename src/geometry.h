#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <vector>
#include <numbers>
#include <algorithm>
#include <SDL3/SDL.h>

namespace Radix
{
	void render_geometry(SDL_Renderer* renderer, const std::vector<SDL_FPoint>& vertices, const SDL_Color& color)
	{
		if(vertices.size() < 2)
		{
			return;
		}

		std::vector<SDL_FPoint> points = vertices;
		points.push_back(vertices.front());

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderLines(renderer, points.data(), static_cast<int>(points.size()));
	}

	void scale_geometry(std::vector<SDL_FPoint>& vertices, float scale_x, float scale_y)
	{
		if(vertices.empty())
		{
			return;
		}

		float min_x = vertices.at(0).x;
		float max_x = vertices.at(0).x;
		float min_y = vertices.at(0).y;
		float max_y = vertices.at(0).y;

		// Find bounding area.
		for(const SDL_FPoint& vertex : vertices)
		{
			min_x = std::min(min_x, vertex.x);
			max_x = std::max(max_x, vertex.x);
			min_y = std::min(min_y, vertex.y);
			max_y = std::max(max_y, vertex.y);
		}

		// Calculate bounding area center.
		const float center_x = (min_x + max_x) * 0.5f;
		const float center_y = (min_y + max_y) * 0.5f;

		// Scale vertices relative to center.
		for(SDL_FPoint& vertex : vertices)
		{
			vertex.x = center_x + (vertex.x - center_x) * scale_x;
			vertex.y = center_y + (vertex.y - center_y) * scale_y;
		}
	}

	void rotate_geometry(std::vector<SDL_FPoint>& vertices, float degrees)
	{
		if(vertices.empty())
		{
			return;
		}

		float min_x = vertices.at(0).x;
		float max_x = vertices.at(0).x;
		float min_y = vertices.at(0).y;
		float max_y = vertices.at(0).y;

		// Find bounding area.
		for(const SDL_FPoint& vertex : vertices)
		{
			min_x = std::min(min_x, vertex.x);
			max_x = std::max(max_x, vertex.x);
			min_y = std::min(min_y, vertex.y);
			max_y = std::max(max_y, vertex.y);
		}

		// Calculate bounding area center.
		const float center_x = (min_x + max_x) * 0.5f;
		const float center_y = (min_y + max_y) * 0.5f;

		// Convert degrees to radians.
		const float radians = degrees * (std::numbers::pi_v<float> / 180.0f);

		const float cos_angle = std::cos(radians);
		const float sin_angle = std::sin(radians);

		// Rotate vertices around center.
		for(SDL_FPoint& vertex : vertices)
		{
			const float x = vertex.x - center_x;
			const float y = vertex.y - center_y;

			vertex.x = center_x + (x * cos_angle - y * sin_angle);
			vertex.y = center_y + (x * sin_angle + y * cos_angle);
		}
	}
}

#endif

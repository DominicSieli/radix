#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <SDL3/SDL.h>

namespace Radix
{
	void render_polygons(SDL_Renderer* renderer, const std::vector<SDL_FPoint>& vertices)
	{
		if(vertices.size() < 2) return;

		std::vector<SDL_FPoint> points = vertices;
		points.push_back(vertices.front());

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderLines(renderer, points.data(), static_cast<int>(points.size()));
	}
}

#endif

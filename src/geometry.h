#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>
#include <SDL3/SDL.h>

namespace Radix
{
	void render_geometry(SDL_Renderer* renderer, const std::vector<SDL_FPoint>& geometry, const SDL_Color& color)
	{
		if(geometry.size() < 2)
		{
			return;
		}

		std::vector<SDL_FPoint> points = geometry;
		points.push_back(geometry.front());

		SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
		SDL_RenderLines(renderer, points.data(), static_cast<int>(points.size()));
	}
}

#endif

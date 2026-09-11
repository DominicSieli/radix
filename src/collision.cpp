#include "collision.h"

namespace radix
{
	bool Collision::check_rect_collision(const SDL_Rect& rect_1, const SDL_Rect& rect_2)
	{
		return (rect_1.x + rect_1.w >= rect_2.x && rect_2.x + rect_2.w >= rect_1.x && rect_1.y + rect_1.h >= rect_2.y && rect_2.y + rect_2.h >= rect_1.y);
	}
}
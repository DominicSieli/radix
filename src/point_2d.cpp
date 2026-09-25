#include <cmath>

#include "point_2d.h"

namespace Radix
{
	Point2D::Point2D()
	{}

	Point2D::~Point2D()
	{}

	Point2D::Point2D(float x, float y)
		: x{x}, y{y}
	{}

	float Point2D::distance(Point2D point_1, Point2D point_2)
	{
		float dx = point_2.x - point_1.x;
		float dy = point_2.y - point_1.y;

		return std::sqrt(dx * dx + dy * dy);
	}
}

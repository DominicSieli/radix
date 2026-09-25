#ifndef POINT_2D_H
#define POINT_2D_H

namespace Radix
{
	class Point2D
	{
		public:
			float x;
			float y;

			Point2D();

			~Point2D();

			Point2D(float, float);

			static float distance(Point2D, Point2D);
	};

}

#endif

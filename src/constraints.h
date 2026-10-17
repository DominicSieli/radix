#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include "entity.h"
#include "vector_2.h"

namespace Radix
{
	void constrain_to_camera_bounds(Entity*);

	bool inside_camera_bounds(const Vector2<float>&, const Vector2<unsigned int>&);
}

#endif

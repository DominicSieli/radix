#ifndef CONSTRAINTS_H
#define CONSTRAINTS_H

#include "entity.h"
#include "vectors.h"

namespace Radix
{
	void constrain_to_camera_bounds(Entity*);

	bool inside_camera_bounds(const Vector2<float>&, const Vector2<float>&);
}

#endif

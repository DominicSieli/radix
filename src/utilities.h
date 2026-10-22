#ifndef UTILITIES_H
#define UTILITIES_H

#include <algorithm>

static inline float clamp_float(const float& value, const float& min, const float& max)
{
	return std::clamp(value, min, max);
}

#endif

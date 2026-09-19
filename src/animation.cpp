#include "animation.h"

namespace Radix
{
	Animation::Animation()
	{}

	Animation::Animation(const unsigned int& index, const unsigned int& frames, const unsigned int& speed)
		: index{index}, frames{frames}, speed{speed}
	{}
}
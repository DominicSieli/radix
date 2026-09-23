#include "animation.h"

namespace Radix
{
	Animation::Animation()
	{}

	Animation::Animation(unsigned int index, unsigned int frames, unsigned int speed)
		: index{index}, frames{frames}, speed{speed}
	{}
}
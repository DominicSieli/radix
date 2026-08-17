#include "animation.h"

namespace radix
{
	Animation::Animation()
	{}

	Animation::Animation(unsigned int index, unsigned int speed, unsigned int frames)
	{
		this->index = index;
		this->speed = speed;
		this->frames = frames;
	}
}
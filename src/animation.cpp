#include "animation.h"

namespace Radix
{
	Animation::Animation()
	{}

	Animation::Animation(const unsigned int& index, const unsigned int& frames, const unsigned int& speed):
		index{index}, frames{frames}, speed{speed}
	{}


	unsigned int Animation::get_index()
	{
		return index;
	}

	void Animation::set_index(const unsigned int& new_index)
	{
		index = new_index;
	}

	unsigned int Animation::get_frames()
	{
		return frames;
	}

	void Animation::set_frames(const unsigned int& new_frames)
	{
		frames = new_frames;
	}

	unsigned int Animation::get_speed()
	{
		return speed;
	}

	void Animation::set_speed(const unsigned int& new_speed)
	{
		speed = new_speed;
	}
}
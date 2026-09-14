#ifndef ANIMATION_H
#define ANIMATION_H

namespace Radix
{
	class Animation
	{
		public:
			unsigned int index;
			unsigned int speed;
			unsigned int frames;

			Animation();

			Animation(unsigned int, unsigned int, unsigned int);
	};
}

#endif
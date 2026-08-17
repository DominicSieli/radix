#ifndef ANIMATION_H
#define ANIMATION_H

namespace radix
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
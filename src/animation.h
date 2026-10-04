#ifndef ANIMATION_H
#define ANIMATION_H

namespace Radix
{
	class Animation
	{
		public:
			float speed;
			unsigned int index;
			unsigned int frames;

			Animation();

			Animation(unsigned int, unsigned int, float);

			~Animation();
	};
}

#endif
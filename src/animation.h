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

			Animation(const unsigned int&, const unsigned int&, const unsigned int&);
	};
}

#endif
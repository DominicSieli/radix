#ifndef ANIMATION_H
#define ANIMATION_H

namespace Radix
{
	class Animation
	{
		private:
			unsigned int index;
			unsigned int frames;
			unsigned int speed;

		public:
			Animation();

			Animation(const unsigned int&, const unsigned int&, const unsigned int&);

			unsigned int get_index();

			void set_index(const unsigned int&);

			unsigned int get_frames();

			void set_frames(const unsigned int&);

			unsigned int get_speed();

			void set_speed(const unsigned int&);
	};
}

#endif
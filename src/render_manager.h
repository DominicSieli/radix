#ifndef RENDER_MANAGER_H
#define RENDER_MANAGER_H

namespace Radix
{
	class RenderManager
	{
		private:
			unsigned int layer_count;

		public:
			RenderManager(const unsigned int);

			~RenderManager();

			unsigned int get_layer_count();

			void render();
	};
}

#endif
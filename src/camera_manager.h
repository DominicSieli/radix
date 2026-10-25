#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <SDL3/SDL.h>

#include "vectors.h"

namespace Radix
{
	class CameraManager
	{
		private:
			SDL_FRect camera;

		public:
			CameraManager();

			~CameraManager();

			void initialize(const float&, const float&, const float&, const float&);

			SDL_FRect get_camera();

			void update_position(const Vector2<float>&, const Vector2<float>&);

			bool is_inside_bounds(const Vector2<float>&, const Vector2<float>&);
	};
}

#endif

#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

#include "time_manager.h"
#include "input_manager.h"
#include "audio_manager.h"
#include "asset_manager.h"
#include "window_manager.h"
#include "camera_manager.h"
#include "render_manager.h"
#include "entity_manager.h"
#include "collision_manager.h"

namespace Radix
{
	class Game
	{
		private:
			bool running = false;

		public:
			inline static TimeManager time_manager{};
			inline static InputManager input_manager{};
			inline static AudioManager audio_manager{};
			inline static AssetManager asset_manager{};
			inline static WindowManager window_manager{};
			inline static CameraManager camera_manager{};
			inline static RenderManager render_manager{};
			inline static EntityManager entity_manager{};
			inline static CollisionManager collision_manager{};

			Game();

			~Game();

			bool is_running();

			void load_level(const unsigned int&);

			void input();

			void update();

			void render();

			void update_camera_movement();

			void check_collisions();

			void process_gameover();

			void process_next_level(const unsigned int&);

			void destroy();
	};
}

#endif
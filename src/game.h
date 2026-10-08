#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <SDL3_image/SDL_image.h>

#include "asset_manager.h"
#include "render_manager.h"
#include "entity_manager.h"
#include "collision_manager.h"

namespace Radix
{
	class AssetManager;
	class RenderManager;
	class EntityManager;
	class CollisionManager;

	class Game
	{
		private:
			bool running = false;
			SDL_Window* window = nullptr;

		public:
			Uint64 previous_tick;
			static SDL_Rect camera;
			static float delta_time;
			static SDL_Event input_event;
			static SDL_Renderer* renderer;
			inline static AssetManager asset_manager{};
			inline static RenderManager render_manager{};
			inline static EntityManager entity_manager{};
			inline static CollisionManager collision_manager{};

			Game();

			~Game();

			bool is_running();

			void load_level(unsigned int);

			void input();

			void update();

			void render();

			void update_camera_movement();

			void check_collisions();

			void process_gameover();

			void process_next_level(unsigned int);

			void destroy();
	};
}

#endif
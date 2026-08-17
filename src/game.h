#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

namespace radix
{
	class AssetManager;

	class Game
	{
		private:
			bool running = false;
			SDL_Window* window = nullptr;

		public:
			int ticks_last_frame = 0;
			static SDL_Event event;
			static SDL_Rect camera;
			static SDL_Renderer* renderer;
			static AssetManager* asset_manager;

			Game();

			~Game();

			bool is_running() const;

			void load_level(int);

			void input();

			void update();

			void render();

			void update_camera_movement();

			void check_collisions();

			void process_gameover();

			void process_next_level(int);

			void destroy();
	};
}

#endif
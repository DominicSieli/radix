#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <string>
#include <SDL3/SDL.h>

#include "entity_manager.h"
#include "transform_component.h"

namespace Radix
{
	class TextComponent: public Component
	{
		private:
			std::string text;
			unsigned int font;
			SDL_Color color;
			SDL_FRect sdl_frect;
			bool fixed_position;

			SDL_FRect position;
			SDL_Texture* texture;
			SDL_Renderer* renderer;

		public:
			TextComponent(const std::string&, const unsigned int&, const SDL_Color&, const SDL_FRect&, const bool&);

			void initialize() override;

			void update(const float&) override;

			void render() override;

			void create_texture();

			void set_text(const std::string&);

			void set_font(const unsigned int&);

			void set_color(const SDL_Color&);

			void set_position(const SDL_FRect&);
	};
}

#endif
#ifndef KEYBOARD_COMPONENT_H
#define KEYBOARD_COMPONENT_H

#include "game.h"
#include "entity_manager.h"
#include "sprite_component.h"
#include "transform_component.h"

namespace radix
{
	class KeyboardComponent: public Component
	{
		public:
			std::string up_key;
			std::string down_key;
			std::string left_key;
			std::string right_key;
			std::string shoot_key;

			SpriteComponent* sprite_component;
			TransformComponent* transform_component;

			KeyboardComponent();

			KeyboardComponent(std::string, std::string, std::string, std::string, std::string);

			std::string sdl_keycode(std::string);

			void initialize() override;

			void update(float) override;
	};
}

#endif
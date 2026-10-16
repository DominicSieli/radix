#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <SDL3/SDL.h>

#include "game.h"
#include "vector_2.h"
#include "entity_manager.h"

namespace Radix
{
	class TransformComponent: public Component
	{
		private:
			Vector2<float> position;
			Vector2<float> scale;
			float rotation;
			Vector2<unsigned int> dimensions;


		public:
			TransformComponent(const Vector2<float>&, const Vector2<float>&, const float&, const Vector2<unsigned int>&);

			void rotate(const float&);

			float get_rotation();

			void set_rotation(const float&);

			void scaling(const Vector2<float>&);

			Vector2<float> get_scale();

			void set_scale(const Vector2<float>&);

			void translate(const Vector2<float>&);

			Vector2<float> get_position();

			void set_position(const Vector2<float>&);

			Vector2<unsigned int> get_dimensions();

			void set_dimensions(const Vector2<unsigned int>&);
	};
}

#endif
#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "vectors.h"
#include "entity_manager.h"

namespace Radix
{
	class TransformComponent: public Component
	{
		private:
			float rotation;
			Vector2<float> scale;
			Vector2<float> position;
			Vector2<float> dimensions;

		public:
			TransformComponent(const Vector2<float>&, const Vector2<float>&, const Vector2<float>&, const float&);

			void rotate(const float&);

			float get_rotation();

			void set_rotation(const float&);

			void scaling(const Vector2<float>&);

			Vector2<float> get_scale();

			void set_scale(const Vector2<float>&);

			void translate(const Vector2<float>&);

			Vector2<float> get_position();

			void set_position(const Vector2<float>&);

			Vector2<float> get_dimensions();

			void set_dimensions(const Vector2<float>&);
	};
}

#endif
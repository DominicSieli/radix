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
		public:
			Vector2<float> position;
			Vector2<float> scale;
			float rotation;

			TransformComponent();

			TransformComponent(const Vector2<float>&, const Vector2<float>&, const float&);

			~TransformComponent() override;

			void initialize() override;

			void update(float) override;

			void render() override;

			void rotate(const float&);

			void set_rotation(const float&);

			void rescale(const Vector2<float>&);

			void translate(const Vector2<float>&);
	};
}

#endif
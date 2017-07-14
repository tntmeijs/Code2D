/*
This component handles everything regarding transforms
Even though almost every object will have this component,
there might be cases in which it is not needed (e.g. managers)
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../ComponentInterface.hpp"

#include "glm/vec2.hpp"
#include "glm/mat4x4.hpp"

namespace Code2D
{
	namespace Component
	{
		class Transform : public ComponentInterface
		{
		public:
			Transform();

			void SetPosition(float x, float y);

			glm::vec2 Position;
			glm::vec2 Size;

			float RotationZ;

		private:
		};
	}
}

#endif
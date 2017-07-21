/*
This component handles everything regarding transforms
Even though almost every object will have this component,
there might be cases in which it is not needed (e.g. managers)
*/

#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../ComponentInterface.hpp"

#include "glad/glad.h"
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

			glm::mat4 CalculateAndGetModelMatrix();
			void SetPosition(GLfloat x, GLfloat y);
			void SetScale(GLfloat x, GLfloat y);

			glm::vec2 Position;
			glm::vec2 Size;
			glm::vec2 Scale;

			// In degrees
			GLfloat RotationZ;
		};
	}
}

#endif
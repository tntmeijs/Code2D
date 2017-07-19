#ifndef CAMERA_2D_HPP
#define CAMERA_2D_HPP

#include "glad/glad.h"
#include "glm/vec2.hpp"
#include "glm/mat4x4.hpp"

namespace Code2D
{
	class Camera2D
	{
	public:
		void Create(GLfloat HorizontalResolution = 1280.0f,
					GLfloat VerticalResolution = 720.0f);

		glm::mat4 CalculateAndGetProjectionViewMatrix() const;

		// Camera looks at this!
		glm::vec2 Center;

		// TODO: rotation on the z-axis

	private:
		glm::mat4 ProjectionMatrix;
		glm::mat4 ViewMatrix;
	};
}

#endif

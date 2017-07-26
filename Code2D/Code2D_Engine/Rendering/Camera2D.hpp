#ifndef CAMERA_2D_HPP
#define CAMERA_2D_HPP

#include "glad/glad.h"
#include "glm/vec2.hpp"
#include "glm/mat4x4.hpp"

/*
This camera is a simple 2D orthogonal camera.
When using this camera, keep in mind that the (0.0; 0.0)
coordinate is the top-left corner!
*/

namespace Code2D
{
	class Camera2D
	{
	public:
		void Create(GLfloat HorizontalResolution = 1280.0f,
					GLfloat VerticalResolution = 720.0f);

		glm::mat4 CalculateAndGetProjectionViewMatrix();

		// Camera looks at this!
		glm::vec2 Center;

		// TODO: rotation on the z-axis

	private:
		glm::mat4 ProjectionMatrix;
		glm::mat4 ViewMatrix;
	};
}

#endif

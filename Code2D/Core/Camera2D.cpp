#include "Camera2D.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Code2D
{
	void Camera2D::Create(GLfloat HorizontalResolution, GLfloat VerticalResolution)
	{
		Center = glm::vec2(0.0f, 0.0f);

		ProjectionMatrix = glm::ortho(0.0f, HorizontalResolution, -VerticalResolution, 0.0f);

		ViewMatrix = glm::lookAt(	glm::vec3(Center, -1.0f),		// The camera is at a height of -1 on the Z axis
									glm::vec3(Center, 0.0f),		// Looking at this coordinate
									glm::vec3(0.0f, 1.0f, 0.0f));	// The world up direction is the Y axis
	}

	glm::mat4 Camera2D::CalculateAndGetProjectionViewMatrix() const
	{
		return (ProjectionMatrix * ViewMatrix);
	}
}

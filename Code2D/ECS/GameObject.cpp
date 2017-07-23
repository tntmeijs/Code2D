#include "GameObject.hpp"
#include "glm/trigonometric.hpp"

namespace Code2D
{
	GameObject::Transform::Transform()
	{
		Position.x = 0.0f;
		Position.y = 0.0f;

		Size.x = 128.0f;
		Size.y = 128.0f;

		RotationZ = 0.0f;

		Scale.x = 1.0f;
		Scale.y = 1.0f;
	}

	void GameObject::Transform::SetPosition(GLfloat x, GLfloat y)
	{
		Position.x = x;
		Position.y = y;
	}

	void GameObject::Transform::SetScale(GLfloat x, GLfloat y)
	{
		Scale.x = x;
		Scale.y = y;
	}

	glm::mat4 GameObject::Transform::CalculateAndGetModelMatrix()
	{
		// These matrices are needed to construct the model matrix
		glm::mat4 TranslationMatrix;
		glm::mat4 ScaleMatrix;
		glm::mat4 RotationMatrix;

		TranslationMatrix[3][0] = Position.x;
		TranslationMatrix[3][1] = Position.y;

		// TODO: uncomment
		ScaleMatrix[0][0] = Size.x * Scale.x;
		ScaleMatrix[1][1] = Size.y * Scale.y;

		// Only has rotate around the Z axis, since we are in 2D space
		RotationMatrix[0][0] = glm::cos(glm::radians(RotationZ));
		RotationMatrix[0][1] = -glm::sin(glm::radians(RotationZ));
		RotationMatrix[1][0] = glm::sin(glm::radians(RotationZ));
		RotationMatrix[1][1] = glm::cos(glm::radians(RotationZ));

		// Read from right to left!
		return (TranslationMatrix * RotationMatrix * ScaleMatrix);
	}
}
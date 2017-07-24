#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "../ECS/Components.hpp"

#include "glad/glad.h"
#include "glm/vec2.hpp"
#include "glm/mat4x4.hpp"

namespace Code2D
{
	class GameObject
	{
	public:
		struct TransformData
		{
			TransformData();
			glm::mat4 CalculateAndGetModelMatrix();
			void SetPosition(GLfloat x, GLfloat y);
			void SetScale(GLfloat x, GLfloat y);

			glm::vec2 Position;
			glm::vec2 Size;
			glm::vec2 Scale;

			// In degrees
			GLfloat RotationZ;
		};

		Components Components;

		// Since a transform is very common, it is part of the game object class
		TransformData Transform;

	private:
	};
}

#endif
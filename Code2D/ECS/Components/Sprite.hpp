/*
This class is a sprite component
It handles all the buffer creation for OpenGL, as well as
storing the texture associated with this component.

I could have made more specialized components, but it felt
as if it would make using the engine much more complicated.
*/

// TODO: instanced rendering!

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "../ComponentInterface.hpp"
#include "../../Core/Shader.hpp"

#include "glad/glad.h"
#include "glm/vec2.hpp"

///#include "glad/glad.h"

namespace Code2D
{
	namespace Component
	{
		class Sprite : public ComponentInterface
		{
		public:
			Sprite();
			void Create(glm::vec2 Position = glm::vec2(0.0f, 0.0f),
						glm::vec2 Size = glm::vec2(0.0f, 0.0f));

			// Returns the VAO
			GLuint Get();

			Shader * PersonalShader;

			GLint LayerZ;

		private:
			// OpenGL buffers
			GLuint VAO, VBO, EBO;
		};
	}
}

#endif
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
#include "../../Rendering/Shader.hpp"
#include "../../Rendering/Texture.hpp"

#include "glad/glad.h"
#include "glm/vec2.hpp"

/*
Every sprite contains a texture for now, this might change later on
during development, though...

When using a sprite, keep in mind that the center of the sprite is the
default origin!
*/

namespace Code2D
{
	namespace Component
	{
		class Sprite : public ComponentInterface
		{
		public:
			Sprite();
			~Sprite();

			void Create(const char * PathToTexture,
						glm::vec2 Position = glm::vec2(0.0f, 0.0f),
						glm::vec2 Size = glm::vec2(0.0f, 0.0f));

			Texture * SpriteTexture;

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
#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "glad/glad.h"
#include "glm/vec4.hpp"

namespace Code2D
{
	class Texture
	{
	public:
		Texture();
		void Create(const char * PathToImage);

		// Returns the texture GLuint
		GLuint Get();

		// (uMin, vMin, uMax, vMax)
		glm::vec4 TextureCoordinates;

	private:
		GLuint TextureID;
	};
}

#endif
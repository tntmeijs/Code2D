#include "Texture.hpp"
#include "stb_image.h"

#include <iostream>

namespace Code2D
{
	Texture::Texture()
	{
		TextureCoordinates = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	}

	void Texture::Create(const char * PathToImage)
	{
		glGenTextures(1, &TextureID);
		glBindTexture(GL_TEXTURE_2D, TextureID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		// Want the retro pixel look for sprites
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		// Loading the image data
		int ImageWidth, ImageHeight, ImageColorChannels;
		unsigned char * ImageByteData = stbi_load(	PathToImage,
													&ImageWidth,
													&ImageHeight,
													&ImageColorChannels,
													4); // Force alpha channel

		if (!ImageByteData)
		{
			std::printf("Could not load %s!\n", PathToImage);
			return;
		}

		glTexImage2D(	GL_TEXTURE_2D,
						0,
						GL_RGBA,
						ImageWidth,
						ImageHeight,
						0,
						GL_RGBA,
						GL_UNSIGNED_BYTE,
						ImageByteData);

		// Image data is no longer needed, because we have already created a texture!
		stbi_image_free(ImageByteData);

		// Unbind because we are done using this buffer
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	GLuint Texture::Get()
	{
		return TextureID;
	}
}
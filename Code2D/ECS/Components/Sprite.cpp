#include "Sprite.hpp"
#include <vector>

constexpr GLuint STRIDE = 4;
constexpr GLuint TEXTURE_UV_OFFSET = 2;

namespace Code2D
{
	namespace Component
	{
		Sprite::Sprite()
		{
			// No custom shader by default
			PersonalShader = nullptr;

			// The texture will be created in the create function...
			SpriteTexture = new Texture;

			// Place the sprite on the default z-layer
			LayerZ = 0;
		}

		Sprite::~Sprite()
		{
			delete PersonalShader;
			delete SpriteTexture;
		}

		void Sprite::Create(const char * PathToTexture, glm::vec2 Position, glm::vec2 Size)
		{
			SpriteTexture->Create(PathToTexture);

			std::vector<GLfloat> VertexData =
			{
				// Vertices			// Texture coordinates (UV)
				0.0f, 0.0f,			0.0f, 1.0f,
				0.0f, 1.0f,			0.0f, 0.0f,
				1.0f, 1.0f,			1.0f, 0.0f,
				1.0f, 0.0f,			1.0f, 1.0f
			};

			std::vector<GLushort> IndexData =
			{
				0, 1, 2,
				0, 2, 3
			};

			// Generate buffers
			glGenVertexArrays(1, &VAO);
			glGenBuffers(1, &VBO);
			glGenBuffers(1, &EBO);

			// Bind buffers
			glBindVertexArray(VAO);
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

			// Vertex data
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * VertexData.size(), VertexData.data(), GL_DYNAMIC_DRAW);

			// Attribute pointers
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * STRIDE, reinterpret_cast<GLvoid*>(0));
			glEnableVertexAttribArray(0);

			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * STRIDE, reinterpret_cast<GLvoid*>(sizeof(GLfloat) * TEXTURE_UV_OFFSET));
			glEnableVertexAttribArray(1);

			// Index data
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort) * IndexData.size(), IndexData.data(), GL_STATIC_DRAW);

			// Unbind buffers
			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		GLuint Sprite::Get()
		{
			return VAO;
		}
	}
}
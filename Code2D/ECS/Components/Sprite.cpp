#include "Sprite.hpp"
#include <vector>

namespace Code2D
{
	namespace Component
	{
		void Sprite::Create(glm::vec2 Position, glm::vec2 Size)
		{
			std::vector<GLfloat> VertexData =
			{
				0.0f, 0.0f,
				0.0f, 1.0f,
				1.0f, 1.0f,
				1.0f, 0.0f
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
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2.0f, reinterpret_cast<GLvoid*>(0));
			glEnableVertexAttribArray(0);

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
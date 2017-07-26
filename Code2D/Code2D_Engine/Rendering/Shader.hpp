#ifndef SHADER_HPP
#define SHADER_HPP

#include "glad/glad.h"
#include <string>

namespace Code2D
{
	class Shader
	{
	public:
		void Create(const char * VertexShaderPath = "<EMPTY>",
					const char * FragmentShaderPath = "<EMPTY>");

		// Returns the shader program
		GLuint & Get();

	private:
		std::string GetShaderSource(const char * PathToShaderSource);
		void CreateShader(GLuint & Shader, GLenum ShaderType, const char * ShaderSourceCode);
		void CreateProgram(GLuint & Program, const GLuint & VertexShader, const GLuint & FragmentShader);

		GLuint ShaderProgram;
	};
}

#endif
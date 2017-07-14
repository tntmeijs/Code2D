#ifndef SHADER_HPP
#define SHADER_HPP

#include "glad/glad.h"

namespace Code2D
{
	class Shader
	{
	public:
		static GLuint CreateProgram(const char * VertexShaderPath = "<EMPTY>",
									const char * FragmentShaderPath = "<EMPTY>");

	private:
	};
}

#endif
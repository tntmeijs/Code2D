#include "Shader.hpp"
#include <fstream>
#include <iostream>

namespace Code2D
{
	void Shader::Create(const char * VertexShaderPath, const char * FragmentShaderPath)
	{
		// Get some shaders
		GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Extract the source code from the files
		std::string VertexSource = GetShaderSource(VertexShaderPath);
		std::string FragmentSource = GetShaderSource(FragmentShaderPath);

		// Create the actual shaders
		CreateShader(VertexShader, GL_VERTEX_SHADER, VertexSource.c_str());
		CreateShader(FragmentShader, GL_FRAGMENT_SHADER, FragmentSource.c_str());
		
		// Link the shaders and create a program
		CreateProgram(ShaderProgram, VertexShader, FragmentShader);
	}

	GLuint & Shader::Get()
	{
		return ShaderProgram;
	}

	std::string Shader::GetShaderSource(const char * PathToShaderSource)
	{
		std::ifstream SourceFile(PathToShaderSource);
		std::string SourceCode;

		if (SourceFile.is_open())
		{
			std::string LineBuffer;
			while (std::getline(SourceFile, LineBuffer))
			{
				SourceCode.append(LineBuffer + "\n");
				LineBuffer.clear();
			}

			// End of file character
			SourceCode.append("\0");

			SourceFile.close();

			return SourceCode;
		}
		else
		{
			// Failed to open the file!
			std::printf("Could not open %s\n", PathToShaderSource);

			return "<ERROR>";
		}
	}
	void Shader::CreateShader(GLuint & Shader, GLenum ShaderType, const char * ShaderSourceCode)
	{
		Shader = glCreateShader(ShaderType);

		// Get strings for glShaderSource.
		glShaderSource(Shader, 1, &ShaderSourceCode, nullptr);

		glCompileShader(Shader);

		GLint IsCompiled = 0;
		glGetShaderiv(Shader, GL_COMPILE_STATUS, &IsCompiled);
		if (IsCompiled == GL_FALSE)
		{
			GLint MaxLength = 0;
			glGetShaderiv(Shader, GL_INFO_LOG_LENGTH, &MaxLength);

			// The maxLength includes the NULL character
			GLchar * Error = new GLchar[MaxLength];
			glGetShaderInfoLog(Shader, MaxLength, nullptr, Error);

			if (ShaderType == GL_VERTEX_SHADER)
			{
				std::printf("Failed to compile the vertex shader!\nError: %s\n", Error);
			}
			else
			{
				std::printf("Failed to compile the fragment shader!\nError: %s\n", Error);
			}

			// Exit with failure.
			glDeleteShader(Shader); // Don't leak the shader.

			// Deallocate the error log memory
			delete[] Error;
			return;
		}

		// Shader compilation is successful.
	}

	void Shader::CreateProgram(GLuint & Program, const GLuint & VertexShader, const GLuint & FragmentShader)
	{
		Program = glCreateProgram();

		//Attach our shaders to our program
		glAttachShader(Program, VertexShader);
		glAttachShader(Program, FragmentShader);

		//Link our program
		glLinkProgram(Program);

		GLint IsLinked = 0;
		glGetProgramiv(Program, GL_LINK_STATUS, &IsLinked);
		if (IsLinked == GL_FALSE)
		{
			GLint MaxLength = 0;
			glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &MaxLength);

			//The maxLength includes the NULL character
			GLchar * Error = new GLchar[MaxLength];
			glGetProgramInfoLog(Program, MaxLength, nullptr, Error);

			std::printf("Failed to create the shader program!\nError: %s\n", Error);

			//We don't need the program anymore.
			glDeleteProgram(Program);

			//Don't leak shaders either.
			glDeleteShader(VertexShader);
			glDeleteShader(FragmentShader);

			// Deallocate the error log memory
			delete[] Error;
			return;
		}

		//Always detach shaders after a successful link.
		glDetachShader(Program, VertexShader);
		glDetachShader(Program, FragmentShader);
	}
}
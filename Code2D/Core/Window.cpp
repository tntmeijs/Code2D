#include "Window.hpp"

namespace Code2D
{
	bool Window::Initialize(short WindowWidth, short WindowHeight)
	{
		this->WindowWidth = WindowWidth;
		this->WindowHeight = WindowHeight;

		// GLFW3 Initialization
		if (!glfwInit())
		{
			return false;
		}
	}
}
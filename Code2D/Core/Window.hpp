#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "GLFW/glfw3.h"

namespace Code2D
{
	class Window
	{
	public:
		bool Initialize(short WindowWidth = 1280, short WindowHeight = 720);

	private:
		short WindowWidth;
		short WindowHeight;

		GLFWwindow * Window;
	};
}

#endif
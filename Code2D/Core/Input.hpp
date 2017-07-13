#ifndef INPUT_HPP
#define INPUT_HPP

#include "GLFW/glfw3.h"

namespace Code2D
{
	class Input
	{
	public:
		static void KeyCallback(GLFWwindow * Window, int Key, int Scancode, int Action, int Mods);

	private:
	};
}

#endif